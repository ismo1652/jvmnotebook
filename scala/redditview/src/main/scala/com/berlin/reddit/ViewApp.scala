package com.berlin.reddit

import javax.swing.JFrame
import com.berlin.reddit.win.View2DPanel
import java.awt.Color

object ViewApp {
	
	def main(args : Array[String]) : Unit = {
			    
		
        val frame = new JFrame("Reddit View")
        val panel2d = new View2DPanel
        
        frame.setBackground(Color.white);
        frame.add(panel2d)
        frame.setLocation(40, 40)  
        frame.pack()
        frame.setResizable(true)
        
        ///////////////////////////////
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE)
        frame.setVisible(true)       
	}
	
} // End of Object //
