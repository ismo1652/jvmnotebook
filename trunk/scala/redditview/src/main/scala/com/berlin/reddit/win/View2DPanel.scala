package com.berlin.reddit.win

import javax.swing.JPanel
import java.awt.Graphics
import java.awt.Graphics2D
import java.awt.Dimension
import java.awt.geom.Ellipse2D
import java.awt.Color
import java.awt.geom._
import java.awt.BasicStroke

import java.awt.Dimension
import java.awt.Font
import java.awt.font.FontRenderContext
import java.awt.font.LineBreakMeasurer
import java.awt.font.TextAttribute
import java.awt.font.TextLayout

import java.text.AttributedCharacterIterator
import java.text.AttributedString

import java.awt.event.KeyListener
import java.awt.event.ActionEvent
import java.awt.event.KeyEvent
import java.awt.EventQueue

import java.util.TimerTask
import java.util.Timer

import org.json._
import org.berlin.net._


class View2DPanel extends JPanel with KeyListener {
	
	var inc = 0
	var panelLoaded = 0 
	var text = "Not Connected"
	var lastUrlName = ""
    var hasDisplayData = 0		
		
	var attribString = new AttributedString(text)
	attribString.addAttribute(TextAttribute.FOREGROUND, Color.blue, 0, text.length())
    attribString.addAttribute(TextAttribute.FONT, new Font("arial", Font.PLAIN, 11), 0, text.length())
	
	setPreferredSize(new Dimension(800, 600))	
	setBackground(Color.white)
	addKeyListener(this)
	setFocusable(true)	
		
	val timer = new Timer()
	val updateTask = new SwingTimerTask() 
	timer.schedule(updateTask, 0, 300);
	      
    def connect() : String = {
		
		val settings = new ConnectSettingsBean("http://www.reddit.com/r/politics/.json?count=" + inc + "&after=" + lastUrlName)
        val connection = new HttpConnect(settings, null)
		System.getProperties().put("http.agent", SystemSettingsBean.USER_AGENT)		
        connection.connect(connection.buildURL())

        val resBuf = new StringBuilder(100)
        val buf = new StringBuilder(100)        
        buf.append(connection.getLastResult().getHtmlData())
        val s = buf.toString        
        val j = new JSONObject(s)
		val d = j.getJSONObject("data")
		val arr = d.getJSONArray("children")
		for (i <- 0 until arr.length) {
			val oj = arr.getJSONObject(i)
			val j2 = oj.getJSONObject("data")
			lastUrlName = j2.getString("name")
			resBuf.append(j2.getString("title"))
			resBuf.append("(" + j2.getString("name") + ")")
			resBuf.append("[" + j2.getString("domain") + "]")
			resBuf.append("                                          |       ")
		}
		
		resBuf.toString
		
	}
    
    def renderTicker(g2d:Graphics2D) = {
    	
    	g2d.setColor(Color.red)    	
    	val rect = new Rectangle2D.Double(10, 14, 20, 16)
    	g2d.draw(rect)         
    	g2d.fill(rect)    	
    	
    }
    
    /**
     * Render the graphics2d display.  This method only gets
     * invoked when the display changes, it is not double buffered.
     */
	override def paintComponent(g:Graphics) = {
		
		super.paintComponent(g)
		val g2d = g.asInstanceOf[Graphics2D]
		g2d.clearRect(0, 0, getWidth(), getHeight())
				
		panelLoaded = 1
		val attribCharIterator = attribString.getIterator()
		val frc = new FontRenderContext(null, false, false)
		val lbm = new LineBreakMeasurer(attribCharIterator, frc)				
		
		var x = 10
		var y = 20.0.asInstanceOf[Float]
		val w = 600
		val wrappingWidth = w - 15
		
		while (lbm.getPosition() < text.length()) {
			
			val layout = lbm.nextLayout(wrappingWidth)
			y = y + layout.getAscent()
			layout.draw(g2d, x, y)
			y = y + layout.getDescent() + layout.getLeading()
		} // End of the While //
		
		if (hasDisplayData == 1) {
			g2d.drawString("...", 4, 10)
			renderTicker(g2d)
		}
		
	}
	
	/**
	 * Connect to the reddit/json site and 
	 * set the text on the graphics 2d display.
	 */
	def connectWithDisplay() = {				
		text = connect()
		attribString = new AttributedString(text)
		attribString.addAttribute(TextAttribute.FOREGROUND, Color.blue, 0, text.length())
		attribString.addAttribute(TextAttribute.FONT, new Font("arial", Font.PLAIN, 11), 0, text.length())						
		repaint()
	}
	
	/**
	 * Event handler method when the key is typed.
	 */
    override def keyTyped(e:KeyEvent) {
		println("Typed -- " + hasDisplayData)
		val c = e.getKeyChar()
		c match {
			case 'c' => { connectWithDisplay }					
			case 'n' => { inc = inc + 50 ; connectWithDisplay }
			case _   => { } 
		} // End of match 
    }
        
    override def keyPressed(e:KeyEvent) { }
        
    override def keyReleased(e:KeyEvent) { }
    
    /**
     * Simple timer task, update the display
     * with the display data flag.
     */
    class SwingTimerTask extends java.util.TimerTask {
    	
    	def doRun() {
    		    		
    		if (panelLoaded == 0) {
    			return
    		}    		
    		if (hasDisplayData == 0) {
    			hasDisplayData = 1
    			repaint()
    		} else {
    			hasDisplayData = 0
    			repaint()
    		} // End of if - else //    		    
    	}
    	def run() {
    		if (!EventQueue.isDispatchThread()) {
    			EventQueue.invokeLater(this)
    		} else {
    			doRun()
    		}
    	}
    } // End of the class //
    
	
} // End of the Class //
