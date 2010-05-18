package com.berlin.wstock.job

import scala.{ Array => ScalaArray }
import java.sql._
import javax.sql.DataSource
import java.util.Properties
import java.io.BufferedReader
import java.io.InputStreamReader

object JobMain {			
	
	def startWithProperty() : Unit = {	
		Class.forName("org.apache.derby.jdbc.EmbeddedDriver").newInstance();		
	}
	
	def main(args : ScalaArray[String]) : Unit = {
		println("INFO: running job with DB server")
		startWithProperty		
		println("INFO: exiting job with DB server")
	}
  
} // End of the Application //
