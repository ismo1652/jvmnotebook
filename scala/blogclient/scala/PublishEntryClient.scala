//**********************************************************
// Copyright (c) 2006-2007.  All rights reserved
// Client to post content to blogger.com
// Compile with the latest Scala compiler.
// 10/26/2007
// Also see: http://code.google.com/apis/blogger/developers_guide_java.html
//**********************************************************
// Import scala Console to avoid IO conflicts
import scala.Console
import scala.io.Source
import scala.List
import java.io._
import java.net._
import java.util._

import com.google.gdata.client._
import com.google.gdata.data._
import com.google.gdata.util._

object PublishEntryClient {
  
  val applicationClientId = "newspirit-client-1"
  val properties     = new Properties()
  val MAXLENGTH = 5000

  //
  // Read the content file.  The first line should contain
  // a "#title summary" line and the rest of the document
  // will contain the "wiki" document.
  class ContentReader(filename: String) {
    import java.io._
    def readFile(): (String, String) = {
      val file = Source.fromFile(filename)
      var counted = file.getLines.counted
      val fileData = new StringBuilder()
      var title = ""
      counted.foreach { (line: String) =>
	  if (counted.count == 0) {
	    title = line.substring(6).trim()
	  } else { 
	    fileData.append(line)
	  }
      }
      (title, fileData.toString())
    }
  } // End of Class //

  def createPost(service: GoogleService, blogid: String, title: String, content: String, 
  			authorName: String, userName: String): Unit = {
        
      // Create the entry to insert
      val myEntry = new Entry()
      myEntry.setTitle(new PlainTextConstruct(title))
      myEntry.setContent(new PlainTextConstruct(content))      
      val author = new Person(authorName, null, userName)
      myEntry.getAuthors().add(author);
      // Ask the service to insert the new entry
      val postUrl = new URL("http://www.blogger.com/feeds/" + blogid + "/posts/default")
      val res = service.insert(postUrl, myEntry)
      Console.println("INFO: create post");
  }    
  def publishEntry(googleUsername: String, googlePwd: String): GoogleService = {
  	val myService = new GoogleService("blogger", applicationClientId)
	myService.setUserCredentials(googleUsername, googlePwd)
	return myService
  }
 
  // Main Client Entry Point  
  def main(args: Array[String]): Unit = {  
    if (args.length != 1) {
      Console.println("usage: PublishEntryClient propertyfile-path (path to property file location)")
      return
    }
    Console.println("Note: PROTECT your google username and password defined in the property file")

    // Load the property file:
    val fprop = new File(args(0))
    properties.load(new FileInputStream(fprop))
    val googleUsername = properties.getProperty("google.username")
    val googlePwd =  properties.getProperty("google.pwd")
    val blogId = properties.getProperty("blog.id")
    val authorFullName = properties.getProperty("author.fullname")
    val postUsername = properties.getProperty("post.username")
    val contentFile = properties.getProperty("content.file")
    if (googleUsername == null || googlePwd == null
	|| blogId == null || authorFullName == null || postUsername == null
        || contentFile == null) {
	  Console.println("ERROR: invalid property file, exiting")
	  return
	}

    Console.println("Reading Content Data...")
    val contentReader = new ContentReader(contentFile)
    val (title, content) = contentReader.readFile()
    Console.println("Publishing Entry... title=" + title)
    val timeStart = System.currentTimeMillis()	
    createPost(publishEntry(googleUsername, googlePwd), blogId,
				title, content, authorFullName, postUsername)	
    val timeEnd = System.currentTimeMillis()
    Console.println("Done...")
    Console.println("Completed processing in " + (timeEnd - timeStart) + " ms.")
  }
}
