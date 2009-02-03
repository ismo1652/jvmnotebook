// http://www.java2s.com/Code/Java/Network-Protocol/Asimpleproxyserver.htm

package com.octane.network.proxy;

import java.io.IOException;
import java.net.ServerSocket;

public class ProxyServer {

	/**
	 * The remote server port that the client will connect to and this class
	 * will bind to.
	 */
	private final int clientBindPort;
	
	/**
	 * The server port that the this local server will connect to.
	 */
	private final int serverConnectPort;
	
	private ServerSocket serverSocket;
	
	public ProxyServer(final int bindLocalPort, final int serverPort) {
		this.clientBindPort = bindLocalPort;
		this.serverConnectPort = serverPort;			
	}
	
	public ProxyServer() {
		this.clientBindPort = 7780;
		this.serverConnectPort = 9081;
	}
	
	public static final MainServerThread createProxyServer() {
		final ProxyServer server = new ProxyServer();		
		return server.new MainServerThread();
	}
	
	private class MainServerThread {
		
		public void initServerSocket() {
			try {				
				serverSocket = new ServerSocket(serverConnectPort);
			} catch (IOException e) {
				e.printStackTrace();
				throw new ProxyServerError(ProxyServerError.ERROR, "Could not create server socket =>" + e);
			}
		}
	}
	
	
	private class ProxyServerThread implements Runnable {

		@Override
		public void run() {
			// TODO Auto-generated method stub
			
		}
								
	} // End of class
	
	private static final void main(final String [] args) {
		
	}
	
}
