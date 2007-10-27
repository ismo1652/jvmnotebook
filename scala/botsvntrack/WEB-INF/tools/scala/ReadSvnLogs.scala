//**********************************************************
// Copyright (c) 2006-2007 Newspiritcompany.com.  All rights reserved
// Berlin Brown
// ReadSvnLogs
//
// 10/26/2007
//**********************************************************

// Import scala Console to avoid IO conflicts
import scala.Console

import java.util.Collection
import java.util.Iterator
import java.util.Set

import java.io._

import org.tmatesoft.svn.core._
import org.tmatesoft.svn.core.auth._
import org.tmatesoft.svn.core.wc._

import org.tmatesoft.svn.core.internal.io.dav.DAVRepositoryFactory
import org.tmatesoft.svn.core.internal.io.fs.FSRepositoryFactory
import org.tmatesoft.svn.core.internal.io.svn.SVNRepositoryFactoryImpl
import org.tmatesoft.svn.core.io.SVNRepository
import org.tmatesoft.svn.core.io.SVNRepositoryFactory

object ReadSvnLogs {

  val options = SVNWCUtil.createDefaultOptions(true)
  val clientManager = SVNClientManager.newInstance(options)
  
  class WCInfoHandler extends ISVNInfoHandler {
    
   def handleInfo (info: SVNInfo) {
     Console.println("Local Path: " + info.getFile().getPath())
     Console.println("URL: " + info.getURL())
     Console.println("Revision: " + info.getRevision().getNumber())
     Console.println("Node Kind: " + info.getKind().toString())
   }

  }

  def readSvnHistory(wcPath: File) {
    val infoHandler = new WCInfoHandler()
    val isRecursive = true
    clientManager.getWCClient().doInfo(wcPath, SVNRevision.WORKING,
				       isRecursive, infoHandler)
  }

  //
  // Main Client Entry Point
  //
  def main(args: Array[String]): Unit = {
  
    if (args.length != 1) {
      Console.println("usage: ReadSvnLogs -f")
      return
    }

    Console.println("Reading Logs...")
    val timeStart = System.currentTimeMillis()
    
    val repoPath = new File("/home/bbrown/workspace/Octaned")

    readSvnHistory(repoPath)

    val timeEnd = System.currentTimeMillis()
    Console.println("Done...")
    Console.println("Completed processing in " + (timeEnd - timeStart) + " ms.")
  }
}

