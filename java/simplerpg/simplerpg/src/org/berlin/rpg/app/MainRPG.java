package org.berlin.rpg.app;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import org.berlin.rpg.RPGCharacter;

public class MainRPG {

    private final RPGCharacter char1 = new RPGCharacter("Dojar");
    private final RPGCharacter char2 = new RPGCharacter("Grind");
    
    public void room() {
        
        System.out.println("You have entered a room with the enemy, prepare to fight!");
        
    }
    
    public void gameLoop() {
        
        // open up standard input
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        this.room();
        try {
            while(true) {
                String lastInputLine = "";
                System.out.println("Enter Command (exit to quit)>>");                
                try {                
                    lastInputLine = br.readLine();
                    if ("exit".equalsIgnoreCase(lastInputLine)) {
                        System.out.println("Exiting Simple RPG");
                        return; /* Exit */
                    } else if ("char".equalsIgnoreCase(lastInputLine)) {
                        System.out.println(char1.toReport());
                    }
                                        
                } catch (IOException ioe) {
                    System.out.println("Error trying to input");           
                } // End of try - catch //
                
            } // End of the while //
        } finally {
            try {
                br.close();
            } catch (IOException e) { }
        } // End of try - finally //
    }
    
    public static void main(final String [] args) {
        
        System.out.println("** The Simple RPG ***");
        final MainRPG rpg = new MainRPG();
        rpg.gameLoop();
    }
    
} // End of the Class //
