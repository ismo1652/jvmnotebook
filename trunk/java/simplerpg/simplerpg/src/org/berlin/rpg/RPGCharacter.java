package org.berlin.rpg;

public class RPGCharacter {

    public static final String CONS = "Constitution";
    public static final String STR  = "Strength";
    public static final String DEX  = "Dexterity";
    public static final String INT  = "Intelligence";
    public static final String CHAR = "Charisma";
    public static final String WIS  = "Wisdom";
    public static final String LUC  = "Luck";
    public static final String MAG  = "Magic";
    
    private final String name;
    
    private int cons = 18;
    private int str = 18;
    private int dex = 18;
    private int intel = 18;
    private int charisma = 18;
    private int wis = 18;
    private int luck = 18;
    private int mag = 18;
    
    public RPGCharacter(final String name) {
        this.name = name;
    }
    
    public String toReport() {
        
        final StringBuilder buf = new StringBuilder();
        buf.append("*******************\n");
        buf.append("* ").append(name).append('\n');
        buf.append("*******************\n");
        buf.append(cons).append('\n');
        buf.append(str).append('\n');
        buf.append(dex).append('\n');
        buf.append(intel).append('\n');
        buf.append(charisma).append('\n');
        buf.append("*******************\n");
        buf.append("* End of Stats\n");
        buf.append("*******************\n");
        return buf.toString();        
    }
    
} // End of the Class //
