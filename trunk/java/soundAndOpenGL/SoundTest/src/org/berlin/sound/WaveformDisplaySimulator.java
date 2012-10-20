package org.berlin.sound;

import java.awt.BorderLayout;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;

import javax.media.Codec;
import javax.media.Format;
import javax.media.PlugInManager;
import javax.media.format.AudioFormat;
import javax.sound.sampled.AudioFileFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.swing.JFrame;

public class WaveformDisplaySimulator {

    public static void main(final String[] args) {
        try {
            
            System.out.println(System.getProperty("java.version"));
            final String MP3 = "com.sun.media.codec.audio.mpa.JavaDecoder";
            Codec mp3 = (Codec) Class.forName(MP3).newInstance();
            
            final Format input1 = new AudioFormat(AudioFormat.MPEGLAYER3);
            final Format input2 = new AudioFormat(AudioFormat.MPEG);
            final Format output = new AudioFormat(AudioFormat.LINEAR);
            PlugInManager.addPlugIn(
                "com.sun.media.codec.audio.mpa.JavaDecoder",                
                new Format[]{ input1, input2 },
                new Format[]{ output },
                PlugInManager.CODEC
            );
            
            final AudioFileFormat.Type [] types = AudioSystem.getAudioFileTypes();
            for (final AudioFileFormat.Type t : types) {
                System.out.println("Returning Type : " + t);
            } // End of the for //

            
            final String PATH = "C:\\Users\\bbrown\\Downloads\\swing-hacks-examples-20060109\\Ch10-Audio\\75\\soundcloud2.mp3"; 
            final JFrame frame = new JFrame("Waveform Display Simulator");
            frame.setBounds(200, 200, 500, 350);

            final File file = new File(PATH);
            final AudioInputStream audioInputStream = AudioSystem.getAudioInputStream(new BufferedInputStream(new FileInputStream(file)));

            final WaveformPanelContainer container = new WaveformPanelContainer();
            container.setAudioToDisplay(audioInputStream);

            frame.getContentPane().setLayout(new BorderLayout());
            frame.getContentPane().add(container, BorderLayout.CENTER);

            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            frame.show();
            frame.validate();
            frame.repaint();

        } catch (final Exception e) {
            e.printStackTrace();
        }
    } // End of the method //

} // End of the class //
