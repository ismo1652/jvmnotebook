/**
 * Based on 
 * http://www.c-sharpcorner.com/UploadFile/mgold/GAAdderDesign09242005053429AM/GAAdderDesign.aspx\
 * 
 * "Using Genetic Algorithms to Design Logic Circuits in C# By  Mike Gold February 05, 2003" 
 * 
 */

using System;
using GeneticAlgorithm;

namespace GEPAlgorithm
{
	/// <summary>
	/// Summary description for Class1.
	/// </summary>
	class Class1
	{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main(string[] args)
		{
			Population p = new Population();
			p.WriteNextGeneration();

			int count = 0;
			while (p.Converged() == false)
			{
				p.NextGeneration();
				if (count % 50 == 0)
					p.WriteNextGeneration();
				count ++;
			}
			//
			// TODO: Add code to start application here
			//
		}
	}
}
