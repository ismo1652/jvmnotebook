/**
 *
 * Copyright (c) 2006-2007 Berlin Brown and botnode.com/Berlin Research  All Rights Reserved
 *
 * http://www.opensource.org/licenses/bsd-license.php

 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:

 * * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * * Neither the name of the Botnode.com (Berlin Brown) nor
 * the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Date: 12/15/2009 
 *   
 * Home Page: http://botnode.com/
 * 
 * Contact: Berlin Brown <berlin dot brown at gmail.com>
 */
package org.berlin.net;

/**
 */
public class SystemSettingsBean {

    public static final String USER_AGENT = "Redditview/1.0 (http://botnode.com) contact:berlin.brown@gmail.com";
    
    private final String httpAgent;
    private final boolean proxySet;
    private final String proxyHost;
    private final int proxyPort;       
            
    /**
     * Constructor for SystemSettingsBean.
     * @param httpAgent String
     * @param enable boolean
     * @param host String
     * @param port int
     */
    public SystemSettingsBean(final String httpAgent, final boolean enable, final String host, final int port) {
        
        this.httpAgent = httpAgent;
        this.proxySet = enable;        
        this.proxyHost = host;
        this.proxyPort = port;       
    }
    
    public SystemSettingsBean(final boolean enable, final String host, final int port) {
        
        this.httpAgent = USER_AGENT;
        this.proxySet = enable;        
        this.proxyHost = host;
        this.proxyPort = port;       
    }
    
    public String toString() {
        return "SystemSettingsBean: proxy=" + this.proxySet + " host=" + this.proxyHost + " port="+ this.proxyPort; 
    }

    /**
     * @return the httpAgent
     */
    public String getHttpAgent() {
        return httpAgent;
    }

    /**
     * @return the proxySet
     */
    public boolean getProxySet() {
        return proxySet;
    }

    /**
     * @return the proxyHost
     */
    public String getProxyHost() {
        return proxyHost;
    }

    /**
     * @return the proxyPort
     */
    public int getProxyPort() {
        return proxyPort;
    }
    
} // End of the Class //
