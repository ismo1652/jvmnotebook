/**
 * Copyright (c) 2006-2010 Berlin Brown and botnode.com  All Rights Reserved
 *
 * http://www.opensource.org/licenses/bsd-license.php

 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * Neither the name of the Botnode.com (Berlin Brown) nor
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
 * WicketApplication.java
 * Nov 7, 2010
 * bbrown
 * Contact: Berlin Brown <berlin dot brown at gmail.com>
 */
package org.berlin.octanewars;

import org.apache.wicket.Page;
import org.apache.wicket.protocol.http.WebApplication;
import org.berlin.octanewars.web.OctaneWarsPage;

/**
 * @author bbrown
 * 
 */
public class WicketApplication extends WebApplication {

    /**
     * Constructor
     */
    public WicketApplication() {
        super();
    }

    /**
     * @see org.apache.wicket.protocol.http.WebApplication#init()
     */
    @Override
    protected void init() {
        getMarkupSettings().setStripWicketTags(true);
    }

    /**
     * @see org.apache.wicket.Application#getHomePage()
     */
    @Override
    public Class<? extends Page> getHomePage() {
        return OctaneWarsPage.class;
    }

} // End of the class
