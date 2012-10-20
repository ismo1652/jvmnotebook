package org.berlin.sound;

import javax.media.Format;
import javax.media.PlugInManager;
import javax.media.format.AudioFormat;
import javax.sound.sampled.AudioFileFormat;
import javax.sound.sampled.AudioSystem;

public class MainSound {

    public static void main(final String [] args) {
        System.out.println("Running");
        System.out.println(System.getProperty("java.version"));        
        final Format input1 = new AudioFormat(AudioFormat.MPEGLAYER3);
        final Format input2 = new AudioFormat(AudioFormat.MPEG);
        final Format output = new AudioFormat(AudioFormat.LINEAR);
        PlugInManager.addPlugIn(
            "com.sun.media.codec.audio.mp3.JavaDecoder",
            new Format[]{ input1, input2 },
            new Format[]{ output },
            PlugInManager.CODEC
        );
        
        final AudioFileFormat.Type [] types = AudioSystem.getAudioFileTypes();
        for (final AudioFileFormat.Type t : types) {
            System.out.println("Returning Type : " + t);
        } // End of the for //        
        System.out.println("Done");
    }
    
} // End of the class //

