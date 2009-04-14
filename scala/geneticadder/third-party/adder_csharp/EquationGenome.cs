using System;
using System.Collections;
using GEPAlgorithm;

namespace GeneticAlgorithm
{
	/// <summary>
	/// Summary description for EquationNode.
	/// Equation node represents a symbolic equation that solves a problem
	/// In this case we'll use the following keys to represent our node
	/// 0: a 1: b 2: *  3: / 4: + 5: -  6: %  7: S (sin) 8: PI 9: Power
	/// </summary>
	/// 
	public class EquationGenome : Genome
	{
		public const int NumSymbols = 4;
		public const int NumFunctions = 4;

		public struct Gene
		{
			public int instruction1;
			public int instruction2;
			public int operation;
		};

		ArrayList TheArray = new ArrayList();
		public static Random TheSeed = new Random((int)DateTime.Now.Ticks);
		int TheMin = 0;
		int TheMax = 6;
		int CurrentXPos = 0;
		int CurrentYPos = 0;
		int PreviousSeed = 2;
		public bool TrialFitness; // this needs to be perfect or else we have to throw out the gene

		public override int CompareTo(object a)
		{
			EquationGenome Gene1 = this;
			EquationGenome Gene2 = (EquationGenome)a;
			return Math.Sign(Gene2.CurrentFitness  -  Gene1.CurrentFitness);
		}


		public override void SetCrossoverPoint(int crossoverPoint)
		{
			CrossoverPoint = 	crossoverPoint;
		}

		public EquationGenome()
		{
		}


		public EquationGenome(long length, object min, object max)
		{

			Length = length;
			TheMin = (int)min;
			TheMax = (int)max;
			CurrentXPos = 0;
			CurrentYPos = 0;

			for (int i = 0; i < Length; i++)
			{
				Gene nextValue = (Gene)GenerateGeneValue(min, max, i);
				TheArray.Add(nextValue);
			}
		}

		public override void Initialize()
		{

		}

		public override bool CanDie(double fitness)
		{
			if (CurrentFitness <= (int)(fitness * 100.0f))
			{
				return true;
			}

			return false;
		}


		public override bool CanReproduce(double fitness)
		{
			if (EquationGenome.TheSeed.Next(100) >= (int)(fitness * 100.0f))
			{
				return true;
			}

			return false;
		}


		public override object GenerateGeneValue(object min, object max, int position)
		{
			Gene g = new Gene();
			int nextSeed = 0;
			nextSeed = TheSeed.Next((int)min, (int)max);
			g.operation = nextSeed;

			if (position == 0) // special case, want to generate a symbol for first one
			{
			   g.operation = TheSeed.Next(0, NumSymbols);  // generate 0 or 1, for a and b
			   return g;
			}

			if (nextSeed > 1) // we have an operation, need postion
			{
				nextSeed = TheSeed.Next((int)min, position);
				g.instruction1 = nextSeed;
				nextSeed = TheSeed.Next((int)min, position);
				g.instruction2 = nextSeed;
			}
			
			return g;
		}

		#region GenerateSmartGene
		/*
				public override object GenerateGeneValue(object min, object max)
				{
					bool hasWall = true;
					int nextSeed = 0;
					int counter = 0;
					while (hasWall)
					{
						nextSeed = TheSeed.Next((int)min, (int)max);
						switch (nextSeed)
						{
							case 0:  // up
								if (PreviousSeed == 2)
								{	
									break; // don't backtrack
								}
								hasWall = TheMaze.HasWall(CurrentXPos, this.CurrentYPos, CurrentXPos, CurrentYPos - 1);
								if (hasWall == false)
								{
								 CurrentYPos--;
								}
								break;
							case 1:  // left
								if (PreviousSeed == 3)
								{	
									break; // don't backtrack
								}

								hasWall = TheMaze.HasWall(CurrentXPos, this.CurrentYPos, CurrentXPos - 1, CurrentYPos);
								if (hasWall == false)
								{
									CurrentXPos--;
								}
								break;
							case 2:  // down
								if (PreviousSeed == 0)
								{	
									break; // don't backtrack
								}
								hasWall = TheMaze.HasWall(CurrentXPos, this.CurrentYPos, CurrentXPos, CurrentYPos + 1);
								if (hasWall == false)
								{
									CurrentYPos++;
								}
								break;
							case 3:  // right
								if (PreviousSeed == 1)
								{	
									break; // don't backtrack
								}

								hasWall = TheMaze.HasWall(CurrentXPos, this.CurrentYPos, CurrentXPos + 1, CurrentYPos);
								if (hasWall == false)
								{
									CurrentXPos++;
								}
								break;
						}

						counter++;
						if (counter > 10)
							break;

					}

					return nextSeed;

				}

		*/

#endregion 



		public override void Mutate()
		{
			int AffectedGenes = TheSeed.Next((int)3); // determine how many genes to mutate
			for (int i = 0; i < AffectedGenes; i++)
			{
				MutationIndex = TheSeed.Next(0, (int)Length);
				//				int val = (int)GenerateGeneValue(TheMin, TheMax);
				TheArray[MutationIndex] = this.GenerateGeneValue(TheMin, TheMax, MutationIndex);
			}

		}


		// This fitness function calculates the fitness of distance travelled
		// from upper left to lower right



		#region fitness2

		// This fitness function calculates the fitness of distance travelled
		/*		// from upper left to lower right
				private double CalculateMazeDistanceFitness()
				{
					double sum = 0.0f;
					int cellPreviousPosX = 0;
					int cellPreviousPosY = 0;
					int cellPosX = 0;
					int cellPosY = 0;
					int trialnumber = 0;
					int backTrack = 0;
					int hasWall = 0;
					int maxConsecutiveNoWalls = 0;
					int consecutiveNoWalls = 0;
					int previousDirection = 0;
					for (int i = 0; i < Length; i++)
					{
						switch ((int)TheArray[i])
						{
							case 0:  // up
								cellPosY--;
								break;
							case 1:  // left
								cellPosX--;
								break;
							case 2:  // down
								cellPosY++;
								break;
							case 3:  // right
								cellPosX++;
								break;
						}

						if ( (previousDirection + 2) % 4 == (int)TheArray[i])
						{
							backTrack++;
						}

						previousDirection = (int)TheArray[i];

						if (maxConsecutiveNoWalls < consecutiveNoWalls)
								maxConsecutiveNoWalls = consecutiveNoWalls;

						if (TheMaze.HasWall(cellPreviousPosX, cellPreviousPosY, cellPosX, cellPosY))
						{
							consecutiveNoWalls = 0;
						}
						else
						{
							consecutiveNoWalls++;
						}

		//				trialnumber++;


						cellPreviousPosX = cellPosX;
						cellPreviousPosY = cellPosY;
					}

					// the score is the distance squared from the origin
					// since the greatest distance is the distance to the destination
					// the lower right hand corner
		//			sum = ((double)(cellPosX*cellPosX + cellPosY*cellPosY))/((double)(Maze.kDimension*Maze.kDimension));  

					sum = sum + ((double)(maxConsecutiveNoWalls))/((double)this.Length);
					sum = sum + ((double)(Length - backTrack))/((double)this.Length);

					sum = sum/2;

					return sum;
				}
		*/

		#endregion 



		public string GetOperationString(int operation)
		{
			string result = "";
			switch(operation)
			{
				case 4: // *
					result = "&";
					break;
				case 5: // / 
					result = "|";
					break;
				case 6: // +
					result = "^";
					break;
				case 7: // - 
					result = "~";
					break;
				default:
					// +
					break;
			} // end switch

			return result;

		}


		public byte DoOperation(byte a, byte b, int operation)
		{
			byte result = 0;
			switch(operation)
			{
				case 4: // and
					result = (byte)(a & b & 1);
					break;
				case 5: // or 
					result = (byte) ((a | b) & 1);
					break;
				case 6: // xor
					result =  (byte)((a ^ b) & 1);
					break;
				case 7: // - 
					result = (byte)((~a) & 1);
					break;
				default:
					// +
					break;
			} // end switch

			return result;

		}

		string[] CalculationStringArray = new string[Population.kLength];

		public string FormStepsString()
		{
			string _result = "\n";

			int count = 0;
			foreach (Gene g in TheArray)
			{
				if (g.operation < NumSymbols)
				{
					// a or b, assign value
					if (g.operation == 0)
						_result += count.ToString() +": " + "a\n";
					else
						_result += count.ToString() +": " + "b\n";
				}
				else if (g.operation == 8)
				{
					_result += count.ToString() +": " + "PI\n";
				}
				else
				{
					// operation, use it to fill calculation in array
					_result += count.ToString() +": " + GetOperationString(g.operation) + " " + g.instruction1.ToString() + ", " + g.instruction2.ToString() + "\n";
				}

				count++;
			}

			_result += "\n\n";
			return _result;
		}


		public string FormEquationString()
		{
			string _result = "";

			int count = 0;
			foreach (Gene g in TheArray)
			{
				if (g.operation < NumSymbols)
				{
					// a or b, assign value

					switch (g.operation)
					{
						case 0:
							CalculationStringArray[count] = "a";
							break;
						case 1:
							CalculationStringArray[count] = "b";
							break;
						case 2:
							CalculationStringArray[count] = "c";
							break;
						case 3:
							CalculationStringArray[count] = "d";
							break;
					}

				}
				else if (g.operation == 8)
				{
					CalculationStringArray[count] = "1";
				}
				else if (g.operation == 7) // unary
				{
					CalculationStringArray[count] =   "(" + CalculationStringArray[g.instruction1] + GetOperationString(g.operation) + ")";
				}
				else if (g.operation == 9) // unary
				{
					CalculationStringArray[count] =   "(" + GetOperationString(g.operation) + CalculationStringArray[g.instruction1]  +  ")" + ")";
				}
				else
				{
					// operation, use it to fill calculation in array
					CalculationStringArray[count] = "(" + CalculationStringArray[g.instruction1] + GetOperationString(g.operation) + CalculationStringArray[g.instruction2] + ")";
				}

				count++;
			}

			_result = CalculationStringArray[Population.kLength - 1];

			return _result;
		}

		byte[] CalculationArray = new byte[Population.kLength];

		public byte PerformCalculation(byte a, byte b, byte c, byte d)
		{
			int count = 0;


		foreach (Gene g in TheArray)
			{
			if (g.operation < NumSymbols)
			{
				// a or b, assign value
				switch (g.operation)
				{
					case 0:
						CalculationArray[count] = a;
						break;
					case 1:
						CalculationArray[count] = b;
						break;
					case 2:
						CalculationArray[count] = c;
						break;
					case 3:
						CalculationArray[count] = d;
						break;
				}
			}
			else
			{
				// operation, use it to fill calculation in array
				CalculationArray[count] = DoOperation(CalculationArray[g.instruction1], CalculationArray[g.instruction2], g.operation);
			}

				count++;
			}

			return CalculationArray[TheArray.Count - 1];  // return last calculation
		}

		
		byte[,] measure = new byte[,]{	  // a  b  c  d
											{0, 0, 0, 0, 0, 0, 0, 0},  
											{0, 0, 0, 1, 0, 0, 0, 1},  
											{0, 0, 1, 0, 0, 0, 1, 0},  
											{0, 0, 1, 1, 0, 0, 1, 1},  
											{0, 1, 0, 0, 0, 0, 0, 1},  
											{0, 1, 0, 1, 0, 0, 1, 0},  
											{0, 1, 1, 0, 0, 0, 1, 1},    
											{0, 1, 1, 1, 0, 1, 0, 0},    
											{1, 0, 0, 0, 0, 0, 1, 0},    
											{1, 0, 0, 1, 0, 0, 1, 1},    
											{1, 0, 1, 0, 0, 1, 0, 0},      
											{1, 0, 1, 1, 0, 1, 0, 1},    
											{1, 1, 0, 0, 0, 0, 1, 1},      
											{1, 1, 0, 1, 0, 1, 0, 0},      
											{1, 1, 1, 0, 0, 1, 0, 1},      
											{1, 1, 1, 1, 0, 1, 1, 0},      
											};
									

//		double[,] measure = new double[12,3]{{-1, -3, 3.162277f},  {30,40,50}, {40, 30, 50}, {1, 1, 1.4142f}, {1, 2, 2.23607f}, {3, 1, 3.162277f}, {6, 13, 14.31782f}, {4,3,5}, {1,3, 3.16228f}, {2, 1, 2.23607f}, {4, 5, 6.403f}, {5,4, 6.403f}};
//		double[,] measure = new double[3,3]{{3,4,5}, {4,3,5}, {1,1,1.4142f}};
		// 3x + 2y = z
	//			 double[,] measure = new double[9,3]{{1,1,5}, {-1, 1, -1}, {1, -1, 1}, {.5f, .1f, 1.7f}, {5, 1, 17}, {-5, 10, 5}, {4,3,18}, {-10,1, -28}, {-2, 3, 0}};


		public double CalculateFullAdder()
		{
			int index = 0;
			// use the node to calculate the fitness

//			Console.WriteLine (EquationNode.OutputStraightEquation(this));

			double calc = 0.0f;
			double sum = 0.0f;
			int count = measure.GetLength(0);
			for (int i = 0; i < count; i++)
			{
				calc = PerformCalculation(measure[i, 0],  measure[i, 1], measure[i,2], measure[i,3]);
//				calc = PerformCalculation(measure[i, 0],  measure[i, 1]);

				// bit 0 fitness
//				double error = 100 - Math.Abs(measure[i,measure.GetLength(1) - 1] - calc); // last byte
				// bit 1 fitness
//				double error = 100 - Math.Abs(measure[i,measure.GetLength(1) - 2] - calc); // last byte
				// bit 2 fitness
				double error = 100 - Math.Abs(measure[i,measure.GetLength(1) - 3] - calc); // last byte
				sum +=  error;
			}
			CurrentFitness = sum/(measure.GetLength(0)*100);

			if (double.IsNaN(CurrentFitness))
				CurrentFitness = 0.01f;

			return CurrentFitness;
		}

		public override double CalculateFitness()
		{
			// CurrentFitness = CalculateClosestProductSum();
			//			CurrentFitness =  CalculateClosestSumTo10();
			//			CurrentFitness = CalculateMazeDistanceFitness();
			CurrentFitness = CalculateFullAdder();
			if (CurrentFitness < 0.0f)
				CurrentFitness = 0.01f;
			return CurrentFitness;
		}


		public override string ToString()
		{
			string strResult = "";
			//			for (int i = 0; i < Length; i++)
			//			{
			//			  strResult = strResult + ((int)TheArray[i]).ToString() + " ";
			//			}

			int index = 0;
			//			TheArray[0] = 5;			
			//			TheArray[1] = 3;			
			//			TheArray[2] = 1;			
			//			TheArray[3] = 0;			
			//			TheArray[4] = 2;		
			// strResult += " -->  " + this.FormStepsString();
	
			strResult += " -->  " + this.FormEquationString();
			strResult += " --> " + CurrentFitness.ToString();

			Gene a = (Gene) TheArray[0];
			Gene b = (Gene) TheArray[1];
			Gene c = (Gene) TheArray[2];
			Gene d = (Gene) TheArray[3];
			Gene e = (Gene) TheArray[4];
			strResult += " [0]=" + a.instruction1 + "/" + a.instruction2  +  "=" +  a.operation;
			strResult += " [1]=" + b.instruction1 + "/" + b.instruction2  +  "=" +  b.operation;
			strResult += " [2]=" + c.instruction1 + "/" + c.instruction2  +  "=" +  c.operation;
			strResult += " [3]=" + d.instruction1 + "/" + d.instruction2  +  "=" +  d.operation;
			strResult += " [4]=" + e.instruction1 + "/" + e.instruction2  +  "=" +  e.operation;
			
			return strResult;
		}

		public override void CopyGeneInfo(Genome dest)
		{
			EquationGenome theGene = (EquationGenome)dest;
			theGene.Length = Length;
			theGene.TheMin = TheMin;
			theGene.TheMax = TheMax;
		}

		public override Genome UniformCrossover(Genome g)
		{
			EquationGenome aGene1 = new EquationGenome();
			EquationGenome aGene2 = new EquationGenome();
			g.CopyGeneInfo(aGene1);
			g.CopyGeneInfo(aGene2);

// swap genes randomly

			EquationGenome CrossingGene = (EquationGenome)g;
			for (int i = 0; i < Length; i++)
			{
				if (TheSeed.Next(100) % 2 == 0)
				{
					aGene1.TheArray.Add(CrossingGene.TheArray[i]);
					aGene2.TheArray.Add(TheArray[i]);
				}
				else
				{
					aGene1.TheArray.Add(TheArray[i]);
					aGene2.TheArray.Add(CrossingGene.TheArray[i]);
				}

			}



			// 50/50 chance of returning gene1 or gene2
			EquationGenome aGene = null;
			if (TheSeed.Next(2) == 1)			
			{
				aGene = aGene1;
			}
			else
			{
				aGene = aGene2;
			}

			return aGene;
		}


		public override Genome Crossover2Point(Genome g)
		{
			EquationGenome aGene1 = new EquationGenome();
			EquationGenome aGene2 = new EquationGenome();
			g.CopyGeneInfo(aGene1);
			g.CopyGeneInfo(aGene2);

			// Pick a random crossover point
			int CrossoverPoint1 = TheSeed.Next(1, (int)Length);
			int CrossoverPoint2 = TheSeed.Next(CrossoverPoint1, (int)Length);
			// normalize
			if (CrossoverPoint1 > CrossoverPoint2)
			{
				int temp = CrossoverPoint1;
				CrossoverPoint1 = CrossoverPoint2;
				CrossoverPoint2 = temp;
			}

			EquationGenome CrossingGene = (EquationGenome)g;

			for (int j = 0; j < CrossoverPoint1; j++)
			{
				aGene1.TheArray.Add(TheArray[j]);
				aGene2.TheArray.Add(CrossingGene.TheArray[j]);
			}

			for (int j = CrossoverPoint1; j < CrossoverPoint2; j++)
			{
				aGene1.TheArray.Add(CrossingGene.TheArray[j]);
				aGene2.TheArray.Add(TheArray[j]);
			}


			for (int j = CrossoverPoint2; j < Length; j++)
			{
				aGene1.TheArray.Add(TheArray[j]);
				aGene2.TheArray.Add(CrossingGene.TheArray[j]);
			}


			// 50/50 chance of returning gene1 or gene2
			EquationGenome aGene = null;
			if (TheSeed.Next(2) == 1)			
			{
				aGene = aGene1;
			}
			else
			{
				aGene = aGene2;
			}

			return aGene;
		}



		public override Genome Crossover(Genome g)
		{
			EquationGenome aGene1 = new EquationGenome();
			EquationGenome aGene2 = new EquationGenome();
			g.CopyGeneInfo(aGene1);
			g.CopyGeneInfo(aGene2);

			// Pick a random crossover point
			CrossoverPoint = TheSeed.Next(1, (int)Length);

			EquationGenome CrossingGene = (EquationGenome)g;
			for (int i = 0; i < CrossoverPoint; i++)
			{
				aGene1.TheArray.Add(CrossingGene.TheArray[i]);
				aGene2.TheArray.Add(TheArray[i]);
			}

			for (int j = CrossoverPoint; j < Length; j++)
			{
				aGene1.TheArray.Add(TheArray[j]);
				aGene2.TheArray.Add(CrossingGene.TheArray[j]);
			}

			// 50/50 chance of returning gene1 or gene2
			EquationGenome aGene = null;
			if (TheSeed.Next(2) == 1)			
			{
				aGene = aGene1;
			}
			else
			{
				aGene = aGene2;
			}

			return aGene;
		}

		public int this[int arrayindex]
		{
			get
			{
				return (int)TheArray[arrayindex];
			}
		}

	}
}
