//////////////////////////////////////////////////////////////////////
// addermain.scala
//////////////////////////////////////////////////////////////////////

import scala.gui._

object canvas extends scala.gui.Application {
  
  val mainWindow = new container.Window {

    var x = 0; var y = 0
   
    val canvas = new widget.Canvas {
      import geom._
      antialiasing = true
      draw(Point(0, 0), Point(x, y))
      paint = new java.awt.GradientPaint(new java.awt.Point(x - 15, y - 15), Color.Red,
        new java.awt.Point(x + 15, y + 15), Color.Blue)
      fill(Circle(Point(x, y), 30))
      foreground = Color.Black
      write("hello", Point(50, 50))
    }

    new java.util.Timer(true).scheduleAtFixedRate(new java.util.TimerTask {
      def run = {
        import geom._
        x = x + 1; y = y + 1
        canvas.clear
        canvas.draw(Point(0, 0), Point(x, y))
        canvas.antialiasing = true
        canvas.paint = new java.awt.GradientPaint(new java.awt.Point(x - 15, y - 15), Color.Red,
          new java.awt.Point(x + 15, y + 15), Color.Blue)
        canvas.fill(geom.Circle(Point(x, y), 30))
        canvas.foreground = Color.Black
        canvas.write("hello", Point(50, 50))
      }
    }, 5000, 50) 

    lay { canvas }

    subscribe(this)

    toplevel eventloop {
      case this.Closing() => System.exit(0)
    }
  }
  
}

//////////////////////////////
// End of File
//////////////////////////////
