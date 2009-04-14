/**
 * Based on 
 * http://www.c-sharpcorner.com/UploadFile/mgold/GAAdderDesign09242005053429AM/GAAdderDesign.aspx\
 * 
 * "Using Genetic Algorithms to Design Logic Circuits in C# By  Mike Gold February 05, 2003" 
 * 
 */
package org.adder;

/**
 * 
 * @author bbrown
 * 
 */
public abstract class Genome implements Comparable {

    /**
	 * 
	 */
    protected long length;

    /**
     * Cross over point.
     */
    protected int crossoverPoint;

    /**
     * Mutation Index.
     */
    protected int mutationIndex;

    /**
     * Current Fitness.
     */
    protected double currentFitness = 0.0f;

    /**
     * Intialize.
     */
    public abstract void initialize();

    /**
     * Mutate.
     */
    public abstract void mutate();

    /**
     * Uniform crossover.
     * 
     * @param g
     * @return
     */
    public abstract Genome uniformCrossover(final Genome g);

    /**
     * Cross over 2 point.
     * 
     * @param g
     * @return
     */
    public abstract Genome crossover2Point(final Genome g);

    /**
     * Cross over.
     * 
     * @param g
     * @return
     */
    public abstract Genome crossover(final Genome g);

    /**
     * Generate gene value.
     * 
     * @param min
     * @param max
     * @param position
     * @return
     */
    abstract public Object generateGeneValue(final int min, final int max,
            final int position);

    /**
     * Set cross over point.
     * 
     * @param crossoverPoint
     */
    public abstract void setCrossoverPoint(final int crossoverPoint);

    /**
     * Calculate Fitness.
     * 
     * @return
     */
    public abstract double calculateFitness();

    /**
     * Can reproduce.
     * 
     * @param fitness
     * @return
     */
    public abstract boolean canReproduce(final double fitness);

    /**
     * Can die.
     * 
     * @param fitness
     * @return
     */
    abstract public boolean canDie(final double fitness);

    /**
     * Copy gene info.
     * 
     * @param g
     */
    public abstract void copyGeneInfo(final Genome g);

} // End of Class
