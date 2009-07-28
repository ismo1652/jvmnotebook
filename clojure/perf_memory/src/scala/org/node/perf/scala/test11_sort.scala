/**
 * Tested with Scala 2.7.5 as of 7/15/2009
 */

package org.node.perf.scala

/*********************************************************************/

object test11_sort {

  // http://en.literateprograms.org/Quicksort_(Scala)
  // From scala home

  def sort[A <% Ordered[A]](xs: List[A]):List[A] = {
    if (xs.isEmpty || xs.tail.isEmpty) xs
    else {
      
      val pivot = xs( xs.length / 2)
      
      // list partition

      // initialize boxes
      var lows: List[A] = Nil
      var mids: List[A] = Nil
      var highs: List[A] = Nil
      
      for( val item <- xs) {

        // classify item
        
        if ( item == pivot) mids = item :: mids
        else if (item < pivot) lows = item :: lows
        else highs = item :: highs
      }

      // return sorted list appending chunks
      
      sort(lows) ::: mids ::: sort(highs) 
    }
  }
  
  def qsort2(lst: List[Int]):List[Int] =
    lst match {
      case Nil => Nil
      case pivot::tail => qsort2(tail filter { _ < pivot }) ::: pivot :: qsort2(tail filter { _ >= pivot })
    }

  def repeat[T](n: Int)(what: => T): List[T] = {
    if (n==0) List()
    else what::repeat(n-1)(what)
  }

  val random = new Random()

  val randomInts: List[Int] = repeat(10)(random.nextInt)

  private def initialize(n: Int): List[Int] = {
    val rand = new java.util.Random(System.currentTimeMillis());  /* [2] */ 

    // fill the list in order
    var a = List.range(0, n - 1);

    // shuffle all elements by randomly exchanging each with one other.
    /*
    for (val i <- Iterator.range(0, n - 1)) {
      val r = rand.nextInt(n);  // generate a random position
      a(i) = r
    }
    */
    val z = a.map[Int](x => rand.nextInt(n))
    z
  }

  def run(n:Int) = {
    val start1 = java.lang.System.nanoTime()
    //val l = repeat(n)(random.nextInt)
    val l = initialize(n)
    val l2 = sort(l)
    val d = l2.length
    val z = d + 1
    val end1 = java.lang.System.nanoTime()
    val diff = (end1 - start1) * 1e-6
    println("Elapsed Time: " + diff + " ms " + z)
  }

  def main(args: Array[String]) = {

    println("Running Server")
    
    sort[Int] (List(5,6,4,2,3,1))
    println(sort[Int] (randomInts))

    // NOTE: this test failed as the quick sort
    // would generate stack errors

    // Stop at 12 by 3
    val range = 0.until(12)
    for (i <- range) {
      val z = Math.pow(3, i).toInt
      println("i-size: " + z)
      run(z)
    }

    println("Done")
  }
  
} // End of Object //


// End of Script //
