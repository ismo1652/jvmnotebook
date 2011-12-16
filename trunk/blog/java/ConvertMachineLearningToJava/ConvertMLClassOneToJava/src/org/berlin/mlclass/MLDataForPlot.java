/**
 * Copyright (c) 2006-2011 Berlin Brown.  All Rights Reserved
 *
 * http://www.opensource.org/licenses/bsd-license.php
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * * Neither the name of the Botnode.com (Berlin Brown) nor
 * the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Date: 8/15/2011
 *  
 * Description: Swing application, plot points from data file, convert machine learning class
 *  example to Java implementation.
 *
 * Home Page: http://code.google.com/u/berlin.brown/
 * 
 * Contact: Berlin Brown <berlin dot brown at gmail.com>
 */
package org.berlin.mlclass;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/*
        Output from example:
        Running
        Done
        INFO: data loaded : ex1data1.txt
        INFO : ScaleX : 31.97766067648516
        INFO : ScaleX : 31.97766067648516
        Theta-->: -3.63029143940436, 1.166362350335582
        For population = 35,000, we predict a profit of : 4519.767867701768
        For population = 70,000, we predict a profit of : 45342.45012944714
        For population = 140,000, we predict a profit of : 126987.81465293789
        INFO : angle 49.39131956808885 rad=0.8620411483678542
        INFO : 0 : 22.203
        INFO : 1 : 24.147
        Still waiting ... 0
 */

/**
 * Convert machine learning class, gradient descent example to Java implementation.
 * This class contains the core machine learning logic.
 * 
 * In this example, we will implement linear regression and apply it to an example dataset.
 * We will implement linear regression with one variable to predict profits for a food truck.
 * 
 * @author berlin brown
 *
 */
public class MLDataForPlot {

    private final MainMLClassToJava graphics;
    
    private final String dataFilename = "ex1data1.txt";
    
    private List<Double[]> data = new ArrayList<Double[]>();    
    private List<Integer[]> renderData = new ArrayList<Integer[]>();
    
    private double scaleX = 1;
    private double scaleY = 1;
    
    private int iterations = 1500;
    private double alpha = 0.01;    
    private double [] lastTheta = { 0, 0 };    
    private double angle = 0;
    private double [] pt0 = { 0, 0 };
    private double [] pt1 = { 0, 0 };
    
    private int [] pt0render = { 0, 0 };
    private int [] pt1render = { 0, 0 };
    
    private double moreOffsetY = 6.0;
    
    /**
     * Constructor.
     * @param graphics
     */
    public MLDataForPlot(final MainMLClassToJava graphics) {
        this.graphics = graphics;
    }
    
    /**
     * Load the data file.
     * @param filename
     */
    public void load(final String filename) { 
        try {
            data = new ArrayList<Double[]>();
            final FileInputStream stream = new FileInputStream(filename);
            final BufferedReader reader = new BufferedReader(new InputStreamReader(stream));
            String data = "";
            do {
                data = reader.readLine();
                if (data == null || data.trim().length() == 0) {
                    continue;
                } else {
                    final String [] line = data.split(",");
                    if (line.length == 2) {
                        try {
                            final double a = Double.parseDouble(line[0]);
                            final double b = Double.parseDouble(line[1]);
                            final Double [] d = { a, b };
                            this.data.add(d);
                        } catch(final NumberFormatException e) {
                            System.out.println(e);
                        }
                    }
                } // End of the if //
            } while(data != null);            
            System.out.println("INFO: data loaded : " + filename);
        } catch(Exception e) {
            e.printStackTrace();
        }                 
    }    
    public void load() {
        this.load(dataFilename);
    }
   
    /**
     * Set scale to convert data point values to values for rendering to screen.
     */
    public void setScale() {        
        final double x = max(this.data, 0);
        final double y = max(this.data, 1);                
        this.scaleX = (graphics.getRenderGridHeight() - 10.0) / x;
        this.scaleY = (graphics.getRenderGridHeight() - 10.0) / y;        
        System.out.println("INFO : ScaleX : " + this.scaleX);        
    }
    
    public void loadForRender() {
        this.setScale();
        this.renderData = new ArrayList<Integer[]>();
        for (final Double [] arr : this.data) {            
            final Integer a = (int)(arr[0] * this.scaleX) + this.graphics.getOffX();
            final int forReverseY = (int)((arr[1]+moreOffsetY) * this.scaleY);
            final Integer b = (this.graphics.getRenderGridHeight() - forReverseY) + this.graphics.getOffY();
            final Integer [] d = { a, b };
            renderData.add(d);
        } // End of the for //
    }
    
    public void render(final Graphics g) {
        g.setColor(Color.red);         
        for (final Integer [] arr : this.renderData) {            
            g.fillRect(arr[0], arr[1], 8, 8);
        }                
        g.setColor(Color.blue);
        final Graphics2D g2 = (Graphics2D)g;            
        g2.setStroke(new BasicStroke(3));
        g.drawLine(this.pt0render[0], this.pt0render[1], this.pt1render[0], this.pt1render[1]);        
    }
    
    public void pmax(final int pos) {
        System.out.println("INFO : " + pos + " : " + this.max(this.data, pos));
    }
    
    public double max(final List<Double[]> d, final int pos) {
        double curr = Double.MIN_VALUE;
        for (final Double [] arr : d) {
            if (arr[pos] > curr) {
                curr = arr[pos]; 
            }
        } // End of the for //
        return curr;
    }
    
    /*
        function [theta, J_history] = gradientDescent2(X, y, theta, alpha, num_iters)         
         m = length(y);         
         for iter = 1:num_iters            
            hthetaByX = X * theta;
            theta0 = theta(1) - (alpha / m) * sum( (hthetaByX - y) .* X(:,1) );
            theta1 = theta(2) - (alpha / m) * sum( (hthetaByX - y) .* X(:,2) );            
            or            
            theta0 = ... sum( (hthetaByX(i) - y(i) * 1 );
            theta1 = ... sum( (hthetaByX(i) - y(i) * X );
            
            theta  = [theta0; theta1];            
         end
        end
     */
    
    protected double [] matrixMultipleHthetaByX(final double [] theta) {
        final double [] vector = new double[this.data.size()];
        int i = 0;                 
        for (final Double [] d : this.data) {
            vector[i] = (1.0 * theta[0]) + (d[0] * theta[1]);            
            i++;
        } // End of the for // 
        return vector;
    }
    
    /**
     * Method to calculate the sum in our equation.
     * 
     * @param theta
     * @param alpha
     * @return
     */
    protected double gradientDescentSumScalar0(final double [] theta, final double alpha) {        
        double sum = 0;
        int i = 0;
        final double [] hthetaByXArr = matrixMultipleHthetaByX(theta); 
        for (final Double [] d : this.data) {
            final double X = 1.0;
            final double y = d[1];
            final double hthetaByX = hthetaByXArr[i];    
            sum = sum + ( (hthetaByX - y) * X );
            i++;
        } // End of the for //
        return sum;
    }
    protected double gradientDescentSumScalar1(final double [] theta, final double alpha) {        
        double sum = 0;
        int i = 0;
        final double [] hthetaByXArr = matrixMultipleHthetaByX(theta);
        for (final Double [] d : this.data) {
            final double X = d[0];
            final double y = d[1];            
            final double hthetaByX = hthetaByXArr[i];         
            sum = sum + ( (hthetaByX - y) * X );
            i++;
        } // End of the for //
        return sum;
    }
    
    public double [] gradientDescent(final double [] theta_in, final double alpha, final int num_iters) {
        final double m = this.data.size();   
        double [] theta = theta_in;
        double theta0 = 0;
        double theta1 = 0;
        for (int i = 0; i < num_iters; i++) {                        
            final double sum0 = this.gradientDescentSumScalar0(theta, alpha);
            final double sum1 = this.gradientDescentSumScalar1(theta, alpha);                                   
            theta0 = theta[0] - ( (alpha / m) * sum0 ); 
            theta1 = theta[1] - ( (alpha / m) * sum1 );                        
            theta = new double [] { theta0, theta1 };
        }
        return theta;
    }
    
    public double [] batchGradientDescent() {
        
        /*
         * From tex:
         * \theta_j := \theta_j - \alpha\frac{1}{m} \sum_{i=1}^m ( h_\theta (x^{(i)})
         */
        
        final double [] theta_in = { 0, 0 };
        double [] theta = this.gradientDescent(theta_in, alpha, iterations);
        this.lastTheta = theta;
        System.out.println("Theta-->: " + theta[0] + ", " + theta[1]);
        return theta;
    }
    
    /**
     * Print prediction examples.
     */
    public void predict() {
        
        // 1x2 times 2x1 == 1x1
        {
            final double [] mA = { 1.0 * 10000, 3.5 * 10000 };
            final double predict1 = (mA[0] * this.lastTheta[0]) + (mA[1] * this.lastTheta[1]);
            System.out.println("For population = 35,000, we predict a profit of : " + predict1);
        }
        
        {
            final double [] mA = { 1.0 * 10000, 7.0 * 10000 };
            final double predict1 = (mA[0] * this.lastTheta[0]) + (mA[1] * this.lastTheta[1]);
            System.out.println("For population = 70,000, we predict a profit of : " + predict1);
        }
        
        {
            final double [] mA = { 1.0 * 10000, 14.0 * 10000 };
            final double predict1 = (mA[0] * this.lastTheta[0]) + (mA[1] * this.lastTheta[1]);
            System.out.println("For population = 140,000, we predict a profit of : " + predict1);
        }
        
        final double [] my0 = { 1.0 , 4.0 };
        final double predicty0 = (my0[0] * this.lastTheta[0]) + (my0[1] * this.lastTheta[1]);
        
        final double [] my1 = { 1.0 , 18.0 };
        final double predicty1 = (my1[0] * this.lastTheta[0]) + (my1[1] * this.lastTheta[1]);        
        final double dx = my1[1] - my0[1];
        final double dy = predicty1 - predicty0; 
        final double angleRadians = Math.atan2(dy, dx);        
        this.angle = Math.toDegrees(angleRadians);      
        System.out.println("INFO : angle " + this.angle + " rad=" + angleRadians);
        
        this.pt0 = new double [] { my0[1], predicty0 };
        this.pt1 = new double [] { my1[1], predicty1 };
        
        /// Convert point for render:
        {
            final Integer a = (int)(my0[1] * this.scaleX) + this.graphics.getOffX();
            final int forReverseY = (int)((predicty0+moreOffsetY) * this.scaleY);
            final Integer b = (this.graphics.getRenderGridHeight() - forReverseY) + this.graphics.getOffY();                       
            this.pt0render = new int [] { a, b };
        }
        
        {
            final Integer a = (int)(my1[1] * this.scaleX) + this.graphics.getOffX();
            final int forReverseY = (int)((predicty1+moreOffsetY) * this.scaleY);
            final Integer b = (this.graphics.getRenderGridHeight() - forReverseY) + this.graphics.getOffY();            
            this.pt1render = new int [] { a, b };
        }                      
    }
    
} // End of the class //
