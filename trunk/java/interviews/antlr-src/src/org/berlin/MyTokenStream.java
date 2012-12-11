package org.berlin;

import org.antlr.runtime.BufferedTokenStream;
import org.antlr.runtime.Token;
import org.antlr.runtime.TokenSource;

public class MyTokenStream extends BufferedTokenStream {
    /**
     * Skip tokens on any channel but this one; this is how we skip
     * whitespace...
     */
    protected int channel = Token.DEFAULT_CHANNEL;

    public MyTokenStream() {
    }

    public MyTokenStream(final TokenSource tokenSource) {
        super(tokenSource);
    }

    public MyTokenStream(final TokenSource tokenSource, int channel) {
        this(tokenSource);
        this.channel = channel;
    }

    /** Always leave p on an on-channel token. */
    @Override
    public void consume() {
        if (p == -1) {
            setup();
        }
        p++;
        sync(p);
        while (tokens.get(p).getChannel() != channel) {
            p++;
            sync(p);
        }
    }

    /**
     * Look backwards
     */
    @Override
    protected Token LB(int k) {
        if (k == 0 || (p - k) < 0)
            return null;

        int i = p;
        int n = 1;
        // find k good tokens looking backwards
        while (n <= k) {
            // skip off-channel tokens
            i = skipOffTokenChannelsReverse(i - 1);
            n++;
        }
        if (i < 0) {
            return null;
        }
        final Token tt = tokens.get(i);
        System.out.println("  #/LB/--->" + tt);
        return tt;
    }

    @Override
    public Token LT(int k) {
        // System.out.println("enter LT("+k+")");
        if (p == -1)
            setup();
        if (k == 0)
            return null;
        if (k < 0)
            return LB(-k);
        int i = p;
        int n = 1; // we know tokens[p] is a good one
        // find k good tokens
        while (n < k) {
            // skip off-channel tokens
            i = skipOffTokenChannels(i + 1);
            n++;
        }
        if (i > range) {
            range = i;
        }
        final Token tt = tokens.get(i);
        System.out.println("    $/LT/--->" + tt);
        return tt;
    }

    /**
     * Given a starting index, return the index of the first on-channel token.
     */
    protected int skipOffTokenChannels(int i) {
        sync(i);
        while (tokens.get(i).getChannel() != channel) { // also stops at EOF
                                                        // (it's onchannel)
            i++;
            sync(i);
        }
        return i;
    }

    protected int skipOffTokenChannelsReverse(int i) {
        while (i >= 0 && tokens.get(i).getChannel() != channel) {
            i--;
        }
        return i;
    }

    @Override
    public void reset() {
        super.reset();
        p = skipOffTokenChannels(0);
    }

    @Override
    protected void setup() {
        p = 0;
        sync(0);
        int i = 0;
        while (tokens.get(i).getChannel() != channel) {
            i++;
            sync(i);
        }
        p = i;
    }

    /** Count EOF just once. */
    public int getNumberOfOnChannelTokens() {
        int n = 0;
        fill();
        for (int i = 0; i < tokens.size(); i++) {
            final Token t = tokens.get(i);            
            if (t.getChannel() == channel)
                n++;
            if (t.getType() == Token.EOF)
                break;
        }
        return n;
    }

    /** Reset this token stream by setting its token source. */
    @Override
    public void setTokenSource(TokenSource tokenSource) {
        super.setTokenSource(tokenSource);
        channel = Token.DEFAULT_CHANNEL;
    }
} // End of the class //
