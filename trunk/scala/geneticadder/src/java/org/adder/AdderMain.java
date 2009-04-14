package org.adder;

public class AdderMain {

	public static final void main(final String [] args) {
		
		System.out.println("Running");
		
		final Population p = new Population();
		p.writeNextGeneration();

		int count = 0;
		while (p.converged() == false) {
			
			p.nextGeneration();
			if (count % 50 == 0) {
				p.writeNextGeneration();
			}
			count++;
		}
		
		System.out.println("Done");
		
	}
		
}
