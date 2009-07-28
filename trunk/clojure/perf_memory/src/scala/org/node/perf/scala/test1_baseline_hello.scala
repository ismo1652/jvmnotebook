/**
 * Tested with Scala 2.7.5 as of 7/15/2009
 */

package org.node.perf.scala

/*********************************************************************/

object test1_baseline {
   
  def main(args: Array[String]) = {
    println("Running Server")
    val start1 = java.lang.System.nanoTime()
    
    val range = 0.until(1000000)
    for (i <- range) {
      val z = 2.2 * 4.1 * 5.4
      val b = z * 1.0
      b
    } // End of for //
    val end1 = java.lang.System.nanoTime()
    val diff = (end1 - start1) * 1e-6
    println("Elapsed Time: " + diff + " ms")
    println("Done")
  }
  
} // End of Object //


// End of Script //
