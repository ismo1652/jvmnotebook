//
// Berlin Brown
//
// $Id: BPLayer.java,v 1.1.1.1 2004/04/26 13:27:28 bigbinc Exp $
//
// author      Simon Levy
//

package org.retro.neural;

import java.util.Enumeration;
import java.util.Random;
import java.util.Stack;

public class BPLayer {

    protected SNVector a;	    // activation
    protected SNVector a1;	    // previous activation
    protected SNVector b;	    // bias
    protected SNVector db;	    // change in bias
    protected SNVector db1;	    // previous change in bias
    protected SNVector e;	    // error
    protected SNVector d;	    // delta
    protected SNMatrix p;           // input or target patterns
    protected SNVector bptt_db;     // change in bias for BPTT
    protected SNVector bptt_e1;     // previous error for BPTT
    protected Stack bptt_ah;        // activation history for BPTT
    protected boolean marked;       // flag for visited in activate/backprop
    protected BPNetwork net;        // network to which this layer belongs
    protected java.util.Vector in;  // incoming connections
    protected java.util.Vector out; // outgoing connections
    protected java.util.Vector dly; // incoming delays
    protected SNMatrix sqrerrs;     // squared errors

    /**
     * Creates a neural network layer.  Activation function for
     * non-input layers is the logistic sigmoid <I>f</I>(<I>x</I>) =
     * 1/(1+exp(-<I>x</I>)), whose first derivative is
     * <I>f(x)</I>*(1-<I>f(x)</I>).  These defaults can be overridden by
     * subclassing with a class that defines the
     * <b><TT>actfun</TT></b> and <b><TT>actdev</TT></b> methods.
     *
     * @param siz number of units in the layer
     */
    public BPLayer (int siz) {
	in = new java.util.Vector();
	out = new java.util.Vector();
        dly = new java.util.Vector();
        a = new SNVector(siz);
    }

    /**
     * Applies layer's activation function to net input.  Override
     * this method to get different activation functions.
     * @param xnet net input to activation function
     * @return activations
     */
    public double actfun(double xnet) { 
	return 1 / (1 + Math.exp(-xnet)); // logistic sigmoid
    }


    /**
     * Applies first derivative of layer's activation function to
     * <i>activation</i> on unit (not net input).  Override this
     * method to get different activation functions.
     * @param xact activation on unit
     * @return first deriviative of activation
     */
    public double actdev(double xact) { 
	return xact * (1 - xact); // sigmoid derivative
    }


    /**
     * Returns out-of-bounds value for don't-care condition.
     * @return don't-care value
     */
    public double dontCare() {
	return _actmax() + 1;
    }

    /**
     * Randomizes biases and weights on this layer. Creates random
     * weights and biases using specified random seed, supporting
     * reproducible experiments.
     *
     * @param seed seed for random number generator
     */
    public void randomize(long seed) {

	Random r = new Random(seed);
	randomize(r);
    }


    /**
     * Same as <TT><b>randomize</b>(seed)</TT>, with arbitrary <TT>seed</TT>.
     */
    public void randomize() {

	Random r = new Random();
	randomize(r);
    }


    /**
     * Randomizes biases and weights on this layer to values normally
     * distributed around zero. Creates random weights and biases
     * using specified random number generator, supporting
     * reproducible experiments.
     *
     * @param r random number generator
     */
    public void randomize(Random rand) {

	// random bias
	b = SNVector.gaussianNoise(size(), rand);

	// random incoming sigma weights
        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    c.randomize(rand);
	}	

	// existing squared errors are invalid
	sqrerrs = null;
    }


    /**
     * Sets weights on this layer from another (Sigma connection) to
     * values in 2D array.  Array should have <I>M</I> rows and
     * <I>N</I> columns, where <I>M</I> is the number of units in
     * this layer, and <I>N</I> is the number in the connected-from
     * layer.
     *
     * @param from the layer connected from
     * @param w the matrix of weights
     * @throws BPConnectException if there is no such conenction
     * @throws BPSizeException if array size mismatches layer sizes
     */
    public void setWeights(BPLayer from, double [][] w) 

	throws BPConnectException, BPSizeException {

        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    if (c.connectedFrom(this, from)) {
	        BPSigmaConnection sc = (BPSigmaConnection)c;
		SNMatrix ww = new SNMatrix(w);
		sc.setWeights(ww); 
		return;
	    }
	}

	// existing squared errors are invalid
	sqrerrs = null;
    }


    /**
     * Sets weights on this layer from two others (Sigma-Pi
     * connection) to values in array of 2D arrays.  The array should
     * have <I>K</I> elements of <I>M</I> rows and <I>N</I> columns,
     * where <I>K</I> is the number of units in this layer, <I>M</I> is
     * the number of units in the first connected-from layer, and
     * <I>N</I> is the number in the second connected-from layer.
     *
     * @param from1 layer connected from
     * @param from2 layer connected from
     * @param w array of weights
     * @throws BPConnectException if there is no such conenction
     * @throws BPSizeException if array size mismatches layer sizes
     */
    public void setWeights(BPLayer from1, BPLayer from2, double [][][] w) 
	throws BPConnectException, BPSizeException {

        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    if (c.connectedFrom(this, from1, from2)) {
	        BPSigmaPiConnection spc = (BPSigmaPiConnection)c;
		SNMatrix [] ww = new SNMatrix[w.length];
		for (int k=0; k<w.length; ++k) {
		    ww[k] = new SNMatrix(w[k]);
		}
		spc.setWeights(ww);
		return;
	    }
	}

	// existing squared errors are invalid
	sqrerrs = null;
    }

    /**
     * Sets bias on this layer to the values in vector.  
     *
     * @param v the vector of bias values
     * @throws BPSizeException if vector size doesn't equal layer size
     */
    public void setBias(double [] v) throws BPSizeException {

	if (v.length != size()) {
	    throw new BPSizeException("BPLayer size doesn't match argument");
	}

	b = new SNVector(v);

	// existing squared errors are invalid
	sqrerrs = null;
    }


    /**
     * Returns the weights on this layer from another layer (Sigma
     * connection), as a 2D array.  The array will have <I>M</I> rows
     * and <I>N</I> columns, where <I>M</I> is the number of units in
     * this layer, and <I>N</I> is the number in the connected-from
     * layer.
     *
     * @param from the layer connected from
     * @return connection weights from that layer to this
     * @throws BPConnectException if there is no such conenction
     * @throws BPInitException some network weights are uninitialized
     */
    public double [][] getWeights(BPLayer from)

	throws BPConnectException, BPInitException {

        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    if (c.connectedFrom(this, from)) {
	        BPSigmaConnection sc = (BPSigmaConnection)c;
		if (sc.emptyWeights()) throw new BPInitException();
		SNMatrix a = sc.getWeights();
		return a.getValues();
	    }
	}

	throw new BPConnectException("No connection between these layers");
    }


    /**
     * Returns the weights on this layer from two other layers
     * (Sigma-Pi connection), as an array of 2D arrays.  The array
     * will have <I>K</I> elements of <I>M</I> rows and <I>N</I>
     * columns, where <I>K</I> is the number of units in this layer,
     * <I>M</I> is the number of units in the first connected-from
     * layer, and <I>N</I> is the number in the second connected-from layer.
     *
     * @param from1 layer connected from
     * @param from2 layer connected from
     * @return connection weights from those layers to this
     * @throws BPConnectException if there is no such conenction
     * @throws BPInitException some network weights are uninitialized
     */
    public double [][][] getWeights(BPLayer from1, BPLayer from2)

	throws BPConnectException, BPInitException {

        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    if (c.connectedFrom(this, from1, from2)) {
	        BPSigmaPiConnection spc = (BPSigmaPiConnection)c;
		if (spc.emptyWeights()) throw new BPInitException();
		SNMatrix [] a = spc.getWeights();
		double [][][] w = new double [a.length][][];
		for (int k=0; k<a.length; ++k) {
		    w[k] = a[k].getValues();
		}
		return w;
	    }
	}

	throw new BPConnectException("No connection among these layers");
    }

    /**
     * Returns the bias on this layer.
     *
     * @return vector of bias values
     * @throws BPInitException if the bias is uninitialized
     */
    public double [] getBias()  throws BPInitException {
	if (b == null) throw new BPInitException();
	return b.getValues();
    }


    /**
     * Returns Root-Mean-Squared error on layer over all training
     * patterns. Network weights must be set before this method is
     * invoked, or an exception will be raised.  The sizes of the
     * input and output patterns must be be compatible, or an
     * exception will be raised.
     *
     * @return RMS error
     * @throws BPInitException if the weights are uninitialized
     * @throws BPSizeException if number of input and output patterns differs
     */
    public double getRMSError() 
	throws BPInitException, BPSizeException {

	int patlen = net.trainCheck();
	return rmserr(patlen);
    }


    /**
     * Returns error of maximum magnitude on layer over all training
     * patterns.  <b><TT>Network.init</TT></b> must be called between
     * network creation and this method, or an exception will be
     * raised.  The number of input and output patterns must be be
     * equal, or an exception will be raised.
     *
     * @return maximum error
     * @throws BPInitException if some network weights are uninitialized
     * @throws BPSizeException if number of input and output patterns differs
     */
    public double getMaxError() 
	throws BPInitException, BPSizeException {

	int patlen = net.trainCheck();
	return maxerr(patlen);
    }

    /**
     * Returns squared errors on layer over all training patterns.
     * <b><TT>Network.init</TT></b> must be called between network
     * creation and this method, or an exception will be raised.  The
     * number of input and output patterns must be be equal, or an
     * exception will be raised.
     *
     * @return array of squared errors
     * @throws BPInitException if some network weights are uninitialized
     * @throws BPSizeException if number of input and output patterns differs
     */
    public double [][] getSquaredErrors() 

	throws BPInitException, BPSizeException {

	int patlen = net.trainCheck();
	return _get_sqrerrs(patlen).getValues();
    }


    /** 
     * Makes a normal (full, Sigma) connection to <TT>this</TT> layer
     * from another layer.  The activations <I>a<SUB>j</SUB></I> on
     * <TT>this</TT> layer is computed as <I>a<SUB>j</SUB> = f</I> (
     * <I>&sum<SUB>i</SUB>a<SUB>i</SUB>w<SUB>ji</SUB> +
     * b<SUB>j</SUB></I> ), where <I>a<SUB>i</SUB></I> are the
     * activations on the other layer, <I>w</I> are the weights
     * between the layers, <I>b</I> are the biases on <TT>this</TT>
     * layer, and <I>f</I> is the layer's activation function. Weights
     * and biases can be initialized via the <TT>randomize</TT> or
     * <TT>setWeights</TT> and <TT>setBias</TT> methods.
     *
     * @param from layer to connect from
     */
    public void connect(BPLayer from) {

	_makenet(from);
	net.connect(from, this);

	BPSigmaConnection c = new BPSigmaConnection(from, this);
	from.out.add(c);
	this.in.add(c);
    }


    /**
     * Makes a Sigma-Pi connection to this layer from two other layers.
     * The activation on <TT>this</TT> layer is computed as
     * <I>a<SUB>k</SUB> = f</I> ( <I>&sum<SUB>i</SUB>&sum<SUB>j</SUB>
     * a<SUB>i</SUB>a<SUB>j</SUB> w<SUB>kji</SUB> + b<SUB>k</SUB></I> ),
     * where <I>a<SUB>i</SUB></I> and <I>a<SUB>j</SUB></I> are the
     * activations on the other two layers <I>w</I> are the weights
     * between the layers, <I>b</I> are the biases on <TT>this</TT>
     * layer, and <I>f</I> is the layer's activation function. Weights
     * and biases can be initialized via the <TT>randomize</TT> or
     * <TT>setWeights</TT> and <TT>setBias</TT> methods. 
     * @param from1 layer to connect from
     * @param from2 layer to connect from
     */
    public void connect(BPLayer from1, BPLayer from2) {

	_makenet(from1);
	_makenet(from2);

	net.connect(from1, from2, this);

	BPSigmaPiConnection c = new BPSigmaPiConnection(from1, from2, this);

	from1.out.add(c);
	from2.out.add(c);
	this.in.add(c);
    }



    /**
     * Attaches pattern to layer as input or target.  Width (number of
     * columns) of pattern must match layer size. Pattern matrices
     * should contain one pattern per row.  For example, <TT><b>A =
     * {{0,0}, {0,1}, {1,0}, {1,1}}, B = {{0}, {1}, {1}, {0}}</b></TT>
     * are the patterns for learning <TT><b>B =
     * XOR(A)</b></TT>. Don't-care conditions are encoded as
     * out-of-bound values. For example, <TT><b>B = {{0}, {1}, {1},
     * {2}}</b></TT> would encode XOR where you don't care about the
     * output <TT><b>B</b></TT> when <TT><b>A = {1,1}</b></TT>.
     *
     * @param pattern pattern to attach
     * @throws BPSizeException on width/size mismatch
     */
    public void attach(double [][] pattern) throws BPSizeException {

	if (pattern[0].length != size()) {
	    throw new BPSizeException("Pattern width must equal layer size");
	}

	p = new SNMatrix(pattern);
    }

    /**
     * Trains all layer's in this layer's network, using
     * back-propagation in batch mode. This means that the errors are 
     * computed over all patterns, and then averaged to compute the
     * weight- and bias- changes. The lengths of any patterns
     * attached to layers and output patterns must be be compatible,
     * or an exception will be raised.
     *
     * @param nep number of epochs for training
     * @param eta learning rate
     * @param mu momentum
     * @param report number of generations between error reports
     * @throws BPInitException if some network weights are uninitialized
     * @throws BPSizeException if lengths of patterns differ
     */
    public void batch(int nep, double eta, double mu, int report) 
	throws BPInitException, BPSizeException {

	net.batch(this, nep, eta, mu, report);
    }


    /**
     * Same as <TT><b>batch</b>(nep, eta, mu, report)</TT>, but with
     * error reporting every second.
     *
     * @param nep number of epochs for training
     * @param eta learning rate
     * @param mu momentum
     * @throws BPInitException if weights hav not been initialized
     * @throws BPSizeException if number of input and output patterns differs
     */
    public void batch(int nep, double eta, double mu)
	throws BPInitException, BPSizeException {
	net.batch(this, nep, eta, mu);
    }

    /**
     * Runs one step of back-propagation in batch mode.
     *
     * @param eta learning rate
     * @param mu momentum
     * @throws BPInitException if some network weights haven't been initialized
     * @throws BPSizeException if number of input and output patterns differs
     */
    public void batch(double eta, double mu)
	throws BPInitException, BPSizeException {

	net.batch(eta, mu);
    }


    /**
     * Trains all layers in this layer's network, using
     * back-propagation in on-line mode. This means that the weights
     * and biases are updated after the presentation of each
     * pattern. The lengths of any patterns attached to layers and
     * output patterns must be be compatible, or an exception will be
     * raised.
     *
     * @param nep number of passes through data
     * @param eta learning rate
     * @param mu momentum
     * @param report number of generations between error reports
     * @throws BPInitException if some network weights are uninitialized
     * @throws BPSizeException if lengths of patterns differ
     */
    public void online(int nep, double eta, double mu, int report) 
	throws BPInitException, BPSizeException {

	net.online(this, nep, eta, mu, report);
    }


    /**
     * Same as <TT><b>online</b>(nep, eta, mu, report)</TT>, but with
     * error report every second.
     *
     * @param nep number of epochs for training
     * @param eta learning rate
     * @param mu momentum
     * @throws BPInitException if weights hav not been initialized
     * @throws BPSizeException if number of input and output patterns differs
     */
    public void online(int nep, double eta, double mu)
	throws BPInitException, BPSizeException {

	net.online(this, nep, eta, mu);
    }

    /**
     * Tests a (trained) network layer.
     *
     * @return output patterns
     * @throws BPInitException if some network weights are uninitialized
     * @throws BPSizeException if number of input and output patterns differs
     */
    public double [][] test()
	throws BPInitException, BPSizeException {

	return net.test(this).getValues();
    }


    /**
     * Tests a (recurrent) network layer without any input.
     *
     * @param n number of steps to run
     * @param a intial activation value
     * @return output pattern on layer
     * @throws BPInitException if some network weights are uninitialized
     * @throws BPSizeException if number of input and output patterns differs
     */
    public double [][] test(int n, double a) 
	throws BPInitException, BPSizeException {
	return net.test(this, n, a).getValues();
    }

    /**
     * Makes one-to-one time-delay connection to this layer from the
     * specified layer, using the specified connection strength. This
     * means that this layer's activations will come from a scalar
     * multiple of the activations of the other layer on the previous
     * time step.  On the first time step these activations are are
     * defined be the average value of this layer's activation
     * function (e.g., 0.5 for the logistic simgoid squashing
     * function).  If the layers have different sizes, and exception will
     * be raised.
     *
     * @param from layer to delay from
     * @param weight connection strength
     * @throws BPSizeException if layers have different sizes
     *
     */
    public void delay(BPLayer from, double weight) throws BPSizeException {
	if (size() != from.size()) {
	    throw new BPSizeException("Layers must have same size");
	}
	_makenet(from);
	dly.add(new BPDelay(from, weight));
	net.delay(this);
    }

    /**
     * Same as <TT><b>delay</b>(from, weight)</TT>, with
     * <TT>weight</TT> = 1.0.
     *
     * @param from layer to delay from
     */
    public void delay(BPLayer from) {

	delay(from, 1.0);
    }


    /**
     * Resets previous weight- and bias- changes.  This is only necessary
     * when running one epoch at a time.
     */
    public void resetMu() {
	
	mureset();
    }


    /**
     * Resets current weight- and bias-changes for Back-Prop-Through-Time.
     */
    public void bpttResetEta() {

	dwreset();
    }

    /**
     * Updates weights and bias on layer using the Delta Rule, for 
     * Back-Prop-Through-Time.
     *
     * @param eta learning rate
     * @param mu momentum
     * @param npat total number of patterns
     * @throws BPMomentumException if no momentum has been set on the layer
     */
    public void bpttUpdate(double eta, double mu, int npat) 

	throws BPMomentumException {

	update(eta, mu, npat);

	sqrerrs = null; // squared errors are no longer valid
    }

    /**
     * Activates this layer by clamping activations on another and
     * running a forward pass.  Clamped activations are temporary and
     * do not affect patterns set by <TT>attach</TT>.
     *
     * @param src "source" layer to clamp
     * @param clmp vector of clamping values
     * @return activation of this layer
     * @throws BPConnectException if there is no path between the layers
     * @throws BPInitException if some network weights are uninitialized
     */
    public double [] activate(BPLayer src, double [] clmp) {

	activate(src, new SNVector(clmp));
	return a.getValues();

    }



    /**
     * Steps through one pattern for Back-Prop Thru Time.  Implements a 
     * restricted version of BPTT, specified by the number of ticks in
     * the argument.
     *
     * @param n number of ticks from end of pattern
     * @throws BPInitException if some network weights are uninitialized
     * @throws BPSizeException if lengths of patterns differ
     * @throws IllegalArgumentException if n < 0 or n >= current
     * pattern length
     */
    public void bpttPattern(int n) 
	throws BPInitException, BPSizeException, IllegalArgumentException {
	net.bptt(n);
    }

    /**
     * Steps through one pattern for Back-Prop Thru Time.  Implements the 
     * full BPTT algorithm on the pattern. Same as <TT><b>bptt</b>(n)</TT>, 
     * with <TT>n</TT> = current pattern length - 1.
     *
     * @throws BPInitException if some network weights are uninitialized
     * @throws BPSizeException if lengths of patterns differ
     */
    public void bpttPattern() throws BPInitException, BPSizeException {
	net.bptt();
    }


    /**
     * Reports a value in a friendly way.  This is useful for reporting
     * RMS and maximum error when training one epoch at a time.
     *
     * @param iter iteration number
     * @param maxit maximum number of iterations
     * @param report reporting interval
     * @param value value to report
     * @param stream print stream that reports value
     */
    public static void reportValue(int iter, int maxit, int report, 
				   double value, java.io.PrintStream stream) {

	BPNetwork.reportval(iter, maxit, report, ""+value, stream);
    }


    // activates this layer by clamping activations on another
    protected void activate(BPLayer src, SNVector clmp) 

	throws BPConnectException, BPInitException {

	// make sure this, source are in same network
	if (net == null || net != src.net) {
	    throw new BPConnectException("No path between layers");
	}

	// input layer gets activation directly from clamp
	if (this == src) {
	    a = clmp.copy();
	}

	// other layers recur on their connected-from layers
	else if (in.elements().hasMoreElements()) { // don't clobber delay

	    // recur on incoming layers, checking for missing weights
            for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	      BPConnection c = (BPConnection)i.nextElement();
	      if (c.emptyWeights()) throw new BPInitException();
	      c.activate(src, clmp);
	    }

	    // start with bias
	    a = b.copy();

	    // add products of weights*incoming layers
            for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	        BPConnection c = (BPConnection)i.nextElement();
		a.add(c.forward());
	    }

	    // apply activation function
	    a = _apply_actfun(a);
	}

	// recall activation for delay XXX will this screw up outside
	// calls?
	a1 = a.copy();
    }

    // activate layer using specified input pattern
    protected void activate(int patno) {

	// don't activate if done already
        if (marked) return;

	// input layer gets activation directly from input
	if (in.isEmpty()) {
	    if (p != null) { // delay layer has no pattern
		a = p.getRow(patno);
	    }
	}

	// other layers recur on their connected-from layers
	else if (in.elements().hasMoreElements()) { // don't clobber delay

	    // recur on incoming layers
            for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	      BPConnection c = (BPConnection)i.nextElement();
	      c.activate(patno);
	    }

	    // start with bias
	    a = b.copy();

	    // add products of weights*incoming layers
            for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	        BPConnection c = (BPConnection)i.nextElement();
		//a.add(c.forward());
		a = SNVector.add(a, c.forward());
	    }

	    // apply activation function
	    a = _apply_actfun(a);
	}

	// recall activation for delay
	a1 = a.copy();

	// mark as activated
	mark();
    }

    // resets previous weight and bias changes
    protected void mureset() {

	db1 = new SNVector(size());

	// incoming sigma weights
        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    c.mureset();
	}	
    }


    // resets current weight and bias changes
    protected void dwreset() {
	db = new SNVector(size());
        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    c.dwreset();
	}
    }

    // updates weights, biases using Delta Rule
    protected void update(double eta, double mu, int npat) 

	throws BPMomentumException {

	if (db1 == null) {
	    throw new BPMomentumException();
	}

	if (npat != 1) { // optimization
	    db.divide(npat);
	}
	b.add(SNVector.multiply(db, eta));

	if (mu != 0) { // optimization
	    b.add(SNVector.multiply(db1, mu));
	}

        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    c.etaAdd(eta, npat);
	    if (mu != 0) c.muAdd(mu); // optimization
	}	

	// save current weight, bias changes for momentum
	db1 = db; 

        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    c.mucopy();
	}	
    }

    // returns number of units in layer
    protected int size() {
	return a.length();
    }

    // returns length of pattern
    protected int patlen() {
	return p.getRows();
    }

    // returns true if layer has an attached pattern, false otherwise
    protected boolean hasPattern() {
	return (p != null);
    }

    // returns true if layer is output (no outgoing), else false
    protected boolean isOutput() {
	return out.isEmpty();
    }

    // accumulates weight- and bias-changes on this layer
    protected void dwadd() {

	//db.add(d);
	db = SNVector.add(db, d);

        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();

	    // weight change is product of delta with incoming activation
	    c.dwadd(d);
	}	
    }

    // sets weight- and bias-changes on this layer
    protected void dwset() {
	db = d; // bias change is delta on layer
        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    c.dwset(d);
	}	
    }

    // computes mean (over patterns) of accumulated weight- and
    // bias-changes on this layer
    protected void dwavg(int npat) {
	db.divide(npat);
        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    c.dwavg(npat);
	}	
    }

    // returns true if any weights to this layer are uninitialized, else false
    protected boolean emptyWeights() {
        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    if (c.emptyWeights()) return true;
	}
	return false;
    }
	

    // recursively computes this layer's error using back-propagation
    protected void backprop(int patno) {

	// don't compute error if done already
        if (marked) return;

	// output layer gets error directly from target
	if (out.isEmpty()) {

	    if (p != null) {
		SNVector pat = p.getRow(patno);
		SNVector mask = _dcmask(pat);
		pat.subtract(a);
		pat.arrayMultiply(mask);
		e.add(pat);
	    }
	}

	// non-output gets error recursively via back-prop
	else {

	    // sum over all inputs
            for (Enumeration i = out.elements() ; i.hasMoreElements() ;) {
	      BPConnection c = (BPConnection)i.nextElement();
	      c.backprop(patno);
	      e.add(c.getError(this));
	    }	
	}

	// compute delta
	d = SNVector.arrayMultiply(e, _apply_actdev(a));

	// store squared error for this pattern	
	sqrerrs.setRow(patno, SNVector.arrayMultiply(e, e));

	// mark error as computed
	mark();
    }

    // sets up activation history for Back-Prop-Thru-Time
    protected void bptt_inita() {
	bptt_ah = new Stack();
    }

    // records current activation for Back-Prop-Thru-Time
    protected void bptt_seta() {
	bptt_ah.push(a.copy());
    }

    // retrieves activation history for Back-Prop-Thru-Time
    protected void bptt_geta() {
	a = (SNVector)bptt_ah.pop();
    }

    // resets pattern weights, biases for back-prop thru time
    protected void bptt_dwreset() {
	bptt_db = new SNVector(size());
        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    c.bptt_dwreset();
	}	
    }

    // accumulates weight- and bias-changes on this layer for BPTT
    protected void bptt_dwadd() {

	bptt_db.add(d); // bias change is delta on layer

        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();

	    // weight change is product of delta with incoming activation
	    c.bptt_dwadd(d);
	}	
    }

    // adds average over current pattern to total over all patterns
    protected void bptt_dwavg(int patlen) {
	db.add(SNVector.divide(bptt_db, patlen));
        for (Enumeration i = in.elements() ; i.hasMoreElements() ;) {
	    BPConnection c = (BPConnection)i.nextElement();
	    c.bptt_dwavg(patlen);
	}	
    }

    // update error on a delay layer-from layer for BPTT
    // XXX should we pass this thru the inverse don't-care mask?
    protected void bptt_delayerr() {
        for (Enumeration i = dly.elements() ; i.hasMoreElements() ;) {
	    BPDelay delay = (BPDelay)i.nextElement();
	    SNVector error = (delay.w != 1) ? // optimization
		bptt_e1 : 
                SNVector.multiply(bptt_e1, delay.w);
	    delay.f.e.add(error);
	}
    }

    // store delayed-to errors for next time
    protected void bptt_saverr() {

	//  XXX will this screw up outside calls?
	bptt_e1 = e.copy();
    }

    // init previous error on delayed-to layer to zero
    protected void bptt_errinit() {
	bptt_e1 = new SNVector(size());
    }

    // initialize delayed-to-layer activation to neutral value
    protected void actinit() {
	a.setAll((_actmin() + _actmax())/2);
    }

    // initialize delayed-to-layer activation to specified value
    protected void actinit(double v) {
	a.setAll(v);
    }

    // initialize squared errors
    protected void sqrerrinit(int patlen) {
	sqrerrs = new SNMatrix(patlen, size());
    }

    // update activation on delayed-to layer
    protected void delayact() {
	a = new SNVector(size());
        for (Enumeration i = dly.elements() ; i.hasMoreElements() ;) {
	    BPDelay delay = (BPDelay)i.nextElement();
	    SNVector fa1 = delay.f.a1;
	    if (delay.w != 1) { // optimization
		fa1.multiply(delay.w);
	    }
	    a.add(fa1);
	}
    }

    // reset errors before adding error from previous state, backprop
    protected void errreset() {
	e = new SNVector(size());
    }

    // set marked flag 
    protected void mark() {
	marked = true;
    }

    // reset marked flag 
    protected void unmark() {
	marked = false;
    }

    // return RMS error over patterns, excluding don't-care conditions
    protected double rmserr(int patlen) {
	net.makesqrerrs(patlen);
	return Math.sqrt(sqrerrs.sum() / sqrerrs.ne(0).sum());
    }

    // return maximum error over patterns
    protected double maxerr(int patlen) {
	return Math.sqrt(_get_sqrerrs(patlen).max());
    }

    // returns true if squared errors need to be computed
    protected boolean nosqrerrs() {
	return (sqrerrs == null);
    }

    // returns squared errors, running forward pass if necessary
    private SNMatrix _get_sqrerrs(int patlen) {
	net.makesqrerrs(patlen);
	return sqrerrs;
    }

    // reconciles this layer's network with other's
    private void _makenet(BPLayer other) {

	if (other.net == null) {
	    if (this.net == null) {
		this.net = other.net = new BPNetwork();
	    }
	    else {
		other.net = this.net;
	    }
	}
	else {
	    if (this.net == null) {
		this.net = other.net;
	    }

	    // if both already belong to a net, make all layers in
	    // other layer's net belong to this layer's net
	    else {
		this.net.reconcile(other.net);
	    }
	}
    }

    // return don't-care mask
    private SNVector _dcmask(SNVector pattern) {
	SNVector mask1 = pattern.ge(_actmin());
	SNVector mask2 = pattern.le(_actmax());
	return mask1.and(mask2);
    }

    // return minimum of activation function
    private double _actmin() { 
	return actfun(Double.NEGATIVE_INFINITY);
    }

    // return maximum of activation function
    private double _actmax() { 
	return actfun(Double.POSITIVE_INFINITY);
    }

    // apply activation function to vector
    private SNVector _apply_actfun(SNVector a) {
	double [] x = a.getValues();
	for (int i=0; i<x.length; ++i) {
	    x[i] = actfun(x[i]);
	}
	return new SNVector(x);
    }

    // apply first derivative of activation function to vector
    private SNVector _apply_actdev(SNVector a) {
	double [] x = a.getValues();
	for (int i=0; i<x.length; ++i) {
	    x[i] = actdev(x[i]);
	}
	return new SNVector(x);
    }
} // end of the class ................................
