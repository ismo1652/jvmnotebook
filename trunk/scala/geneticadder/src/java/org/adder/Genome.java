package org.adder;

public abstract class Genome implements Comparable {

	protected long   length;
	protected int    crossoverPoint;
	protected int    mutationIndex;
	protected double currentFitness = 0.0f;
	
	abstract public void     initialize();
	abstract public void     mutate();
	abstract public Genome   uniformCrossover(final Genome g);
	abstract public Genome   crossover2Point(final Genome g);
	abstract public Genome   crossover(final Genome g);
	abstract public Object   generateGeneValue(final int min, final int max, final int position);
	abstract public void     setCrossoverPoint(final int crossoverPoint);
	abstract public double   calculateFitness();
	abstract public boolean  canReproduce(final double fitness);
	abstract public boolean  canDie(final double fitness);	
	abstract public void	 copyGeneInfo(final Genome g);
			
} // End of Class
