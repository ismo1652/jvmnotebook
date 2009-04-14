package org.adder;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class Population {

    public static final int kLength = 20;
    public static final int kInitialPopulation = 500;
    public static final int kPopulationLimit = 500;
    public static final int kMin = 0;
    public static final int kMax = 8;
    public static final double kMutationFrequency = 0.33f;
    public static final double kDeathFitness = 0.00f;
    public static final double kReproductionFitness = 0.0f;

    private int nCrossover = kLength / 2;

    private List scores = new ArrayList();
    private List genomes = new ArrayList();
    private List genomeReproducers = new ArrayList();
    private List genomeResults = new ArrayList();
    private List genomeFamily = new ArrayList();

    private int currentPopulation = kInitialPopulation;
    private int generation = 1;
    private boolean best2 = true;

    /////////////////////////////////////////////////////////////////
    
    public Population() {

        for (int i = 0; i < kInitialPopulation; i++) {

            final EquationGenome aGenome = new EquationGenome(kLength, kMin, kMax);
            int nCrossOver = EquationGenome.nextInt(EquationGenome.TheSeed, 1, (int) aGenome.length);
            aGenome.setCrossoverPoint(nCrossover);
            aGenome.calculateFitness();
            genomes.add(aGenome);

        }

    }

    private void mutate(final Genome aGene) {

        if (EquationGenome.TheSeed.nextInt(100) < (int) (kMutationFrequency * 100.0)) {
            aGene.mutate();
        }
    }

    public static void removeRange(final List elements, final int startIndex, final int endIndex) {
        int index;
        if (startIndex > endIndex) {
            throw new IllegalArgumentException();
        }

        for (index = endIndex; index >= startIndex; index--) {
            elements.remove(index);
        }
    }

    public static final List clone(final List list) {

        final List newList = new ArrayList();
        for (final Iterator it = list.iterator(); it.hasNext();) {
            newList.add(it.next());
        }
        return newList;

    }

    public void nextGeneration() {

        // increment the generation;
        generation++;

        // check who can die
        for (int i = 0; i < genomes.size(); i++) {
            if (((Genome) genomes.get(i)).canDie(kDeathFitness)) {
                genomes.remove(i);
                i--;
            }
        }

        // determine who can reproduce
        genomeReproducers.clear();
        genomeResults.clear();

        for (int i = 0; i < genomes.size(); i++) {
            if (((Genome) genomes.get(i)).canReproduce(kReproductionFitness)) {
                genomeReproducers.add(genomes.get(i));
            }
        }

        // do the crossover of the genes and add them to the population
        doCrossover(genomeReproducers);

        genomes = (List) clone(genomeResults);

        // mutate a few genes in the new population
        for (int i = 0; i < genomes.size(); i++) {
            mutate((Genome) genomes.get(i));
        }

        // calculate fitness of all the genes
        for (int i = 0; i < genomes.size(); i++) {
            ((Genome) genomes.get(i)).calculateFitness();
        }

        // kill all the genes above the population limit
        if (genomes.size() > kPopulationLimit) {
            removeRange(genomes, kPopulationLimit, genomes.size() - kPopulationLimit);
        }

        currentPopulation = genomes.size();
    }

    public void calculateFitnessForAll(final List<EquationGenome> genes) {

        for (EquationGenome lg : genes) {
            lg.calculateFitness();
        }
    }

    public void doCrossover(final List genes) {

        final List geneMoms = new ArrayList();
        final List geneDads = new ArrayList();

        for (int i = 0; i < genes.size(); i++) {

            // randomly pick the moms and dad's
            if (EquationGenome.TheSeed.nextInt(100) % 2 > 0) {
                geneMoms.add(genes.get(i));
            } else {
                geneDads.add(genes.get(i));
            }
        }

        // now make them equal
        if (geneMoms.size() > geneDads.size()) {

            while (geneMoms.size() > geneDads.size()) {
                geneDads.add(geneMoms.get(geneMoms.size() - 1));
                geneMoms.remove(geneMoms.size() - 1);
            }

            if (geneDads.size() > geneMoms.size()) {
                geneDads.remove(geneDads.size() - 1); // make sure they are
                // equal
            }

        } else {

            while (geneDads.size() > geneMoms.size()) {
                geneMoms.add(geneDads.get(geneDads.size() - 1));
                geneDads.remove(geneDads.size() - 1);
            }

            if (geneMoms.size() > geneDads.size()) {
                geneMoms.remove(geneMoms.size() - 1); // make sure they are
                // equal
            }
        }

        // now cross them over and add them according to fitness
        for (int i = 0; i < geneDads.size(); i++) {

            // pick best 2 from parent and children
            EquationGenome babyGene1 = null;
            EquationGenome babyGene2 = null;

            int randomnum = EquationGenome.TheSeed.nextInt(100) % 3;

            if (randomnum == 0) {

                babyGene1 = (EquationGenome) ((EquationGenome) geneDads.get(i)).crossover((EquationGenome) geneMoms.get(i));
                babyGene2 = (EquationGenome) ((EquationGenome) geneMoms.get(i)).crossover((EquationGenome) geneDads.get(i));

            } else if (randomnum == 1) {

                babyGene1 = (EquationGenome) ((EquationGenome) geneDads.get(i)).crossover2Point((EquationGenome) geneMoms.get(i));
                babyGene2 = (EquationGenome) ((EquationGenome) geneMoms.get(i)).crossover2Point((EquationGenome) geneDads.get(i));
            } else {

                babyGene1 = (EquationGenome) ((EquationGenome) geneDads.get(i)).uniformCrossover((EquationGenome) geneMoms.get(i));
                babyGene2 = (EquationGenome) ((EquationGenome) geneMoms.get(i)).uniformCrossover((EquationGenome) geneDads.get(i));

            }

            genomeFamily.clear();
            genomeFamily.add(geneDads.get(i));
            genomeFamily.add(geneMoms.get(i));
            genomeFamily.add(babyGene1);
            genomeFamily.add(babyGene2);

            calculateFitnessForAll(genomeFamily);

            for (int j = 0; j < 4; j++) {

                checkForUndefinedFitness((Genome) genomeFamily.get(j));

            }

            Collections.sort(genomeFamily);

            if (best2) {

                // if Best2 is true, add top fitness genes
                genomeResults.add(genomeFamily.get(0));
                genomeResults.add(genomeFamily.get(1));

            } else {

                genomeResults.add(babyGene1);
                genomeResults.add(babyGene2);
            }

            // if population shrunk, you can add rest of genes
            if (Population.kPopulationLimit < genomes.size()) {

                genomeResults.add(genomeFamily.get(3));
                genomeResults.add(genomeFamily.get(4));
            }
        }

    }

    public void checkForUndefinedFitness(final Genome g) {

        if (Double.isNaN(g.currentFitness)) {
            g.currentFitness = 0.01f;
        }
    }

    public void writeNextGeneration() {

        // just write the top 20
        System.out.println("generation " + generation);
        for (int i = 0; i < currentPopulation; i++) {
            System.out.println(((Genome) genomes.get(i)).toString());
        }

        System.out.println("generation #" + generation + ", Hit the enter key to continue...\n");
        try {
            System.in.read();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public boolean converged() {

        int histogram = 0;
        for (int i = 1; i < scores.size(); i++) {

            final Double ad = (Double) scores.get(i);
            final Double bd = (Double) scores.get(i - 1);
            final double a = ad.doubleValue();
            final double b = bd.doubleValue();
            if ((int) (a * 10000) == (int) (b * 10000)) {

                histogram++;

            } else {

                histogram = 0;

            }
        }

        if (histogram > 5)
            return true;

        return false;
    }

    public void writeNextGenerationBest() {

        Collections.sort(genomes);
        if (genomes.size() > 0) {
            System.out.println(((Genome) genomes.get(0)));
            scores.add(((EquationGenome) genomes.get(0)).currentFitness); 
        }

    } // End of the Method

} // End of Class
