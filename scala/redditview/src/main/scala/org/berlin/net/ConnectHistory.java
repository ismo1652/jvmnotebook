/**
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
 * 
 * Description: Simple java swing web browser for testable websites.
 */
package org.berlin.net;

import java.util.ArrayList;
import java.util.List;

public class ConnectHistory {
       
    private List<ConnectSettingsBean> historyList = new ArrayList<ConnectSettingsBean>();
    private HistoryNode historyPtr = new HistoryNode(this.historyList);
    private ConnectSettingsBean lastConnectBean = null;
    
    public String toString() {
        return "ConnectHistory : " + this.historyList.size();
    }
    
    public void addConnectInfo(final ConnectSettingsBean connect) {
        
        this.lastConnectBean = connect;
        this.historyList.add(connect);
 
        // Rebuild the history list when new elements added //
        this.historyPtr = new HistoryNode(this.historyList);
        this.historyPtr.reset();
        
    }

    /**
     * @return the historyList
     */
    public List<ConnectSettingsBean> getHistoryList() {
        return historyList;
    }

    /**
     * @param historyList the historyList to set
     */
    public void setHistoryList(List<ConnectSettingsBean> historyList) {
        this.historyList = historyList;
    }

    /**
     * @return the lastConnectBean
     */
    public ConnectSettingsBean getLastConnectBean() {
        return lastConnectBean;
    }

    /**
     * @return the historyPtr
     */
    public HistoryNode getHistoryPointer() {
        return historyPtr;
    }

    /**
     * @param historyPtr the historyPtr to set
     */
    public void setHistoryPtr(HistoryNode historyPtr) {
        this.historyPtr = historyPtr;
    }
    
} // End of the Class //
