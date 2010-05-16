package com.berlin.reddit.win

import javax.swing.JPanel
import java.awt.Graphics
import java.awt.Graphics2D
import java.awt.Dimension
import java.awt.geom.Ellipse2D
import java.awt.Color

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

import org.json._
import org.berlin.net._


class View2DPanel extends JPanel with KeyListener {
	
	var inc = 0
	var text = "Not Connected"
	var lastUrlName = ""
		
	var attribString = new AttributedString(text)
	attribString.addAttribute(TextAttribute.FOREGROUND, Color.blue, 0, text.length())
    attribString.addAttribute(TextAttribute.FONT, new Font("arial", Font.PLAIN, 11), 0, text.length())
	
	setPreferredSize(new Dimension(800, 600))	
	setBackground(Color.white)
	addKeyListener(this)
	setFocusable(true)	
	
    var hasDisplayData = 0
    
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
    
	override def paintComponent(g:Graphics) = {
		
		super.paintComponent(g)
		val g2d = g.asInstanceOf[Graphics2D]
		g2d.clearRect(0, 0, getWidth(), getHeight())
				
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
			g2d.drawString("Making Connection...", 4, 12)
			
		}
		
	}
	
	def connectWithDisplay() = {
		hasDisplayData = 1				
		text = connect()
		attribString = new AttributedString(text)
		attribString.addAttribute(TextAttribute.FOREGROUND, Color.blue, 0, text.length())
		attribString.addAttribute(TextAttribute.FONT, new Font("arial", Font.PLAIN, 11), 0, text.length())						
		repaint()
	}
	
    override def keyTyped(e:KeyEvent) {
		println("Typed -- " + hasDisplayData)
		val c = e.getKeyChar()
		c match {
			case 'c' => { connectWithDisplay }
			case 'd' => { hasDisplayData = 0 ; repaint() }			
			case 'n' => { inc = inc + 50 ; connectWithDisplay }
			case _   => { } 
		} // End of match 
    }
        
    override def keyPressed(e:KeyEvent) { }
        
    override def keyReleased(e:KeyEvent) { }
	
} // End of the Class //
