package com.berlin.reddit.win

import javax.swing.JPanel
import java.awt.Graphics
import java.awt.Graphics2D
import java.awt.Dimension
import java.awt.geom.Ellipse2D
import java.awt.Color

class View2DPanel extends JPanel {
		
	setPreferredSize(new Dimension(600, 400))	
	setBackground(Color.white)
	
	override def paintComponent(g:Graphics) = {
		
		super.paintComponent(g)				
		val circle = new Ellipse2D.Double(10, 10, 350, 350)
		val g2d = g.asInstanceOf[Graphics2D]
		g2d.clearRect(0, 0, getWidth(), getHeight())
		//g2d.fill(circle)
		g2d.drawString("Test", 20, 20)
		
	}
	
} // End of the Class //