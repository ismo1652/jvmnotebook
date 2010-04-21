package org.berlin.rpg.rules;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Properties;

import org.drools.KnowledgeBase;
import org.drools.KnowledgeBaseFactory;
import org.drools.builder.KnowledgeBuilder;
import org.drools.builder.KnowledgeBuilderFactory;
import org.drools.builder.ResourceType;
import org.drools.compiler.PackageBuilderConfiguration;
import org.drools.definition.KnowledgePackage;
import org.drools.event.rule.DebugAgendaEventListener;
import org.drools.event.rule.DebugWorkingMemoryEventListener;
import org.drools.io.ResourceFactory;
import org.drools.logger.KnowledgeRuntimeLogger;
import org.drools.logger.KnowledgeRuntimeLoggerFactory;
import org.drools.rule.builder.dialect.java.JavaDialectConfiguration;
import org.drools.runtime.StatefulKnowledgeSession;

public class Rules {
        
    public void rules() {
        
        /*
        final Properties properties = new Properties();  
        properties.setProperty( "drools.dialect.java.compiler", "JANINO" );  
        PackageBuilderConfiguration cfg = new PackageBuilderConfiguration( properties );  
        JavaDialectConfiguration javaConf = (JavaDialectConfiguration)  
        cfg.getDialectConfiguration( "java" );  
        */
        final KnowledgeBuilder kbuilder = KnowledgeBuilderFactory.newKnowledgeBuilder();

        // this will parse and compile in one step
        kbuilder.add(ResourceFactory.newClassPathResource("HelloWorld.drl", Rules.class), ResourceType.DRL);

        // Check the builder for errors
        if (kbuilder.hasErrors()) {
            System.out.println(kbuilder.getErrors().toString());
            throw new RuntimeException("Unable to compile \"HelloWorld.drl\".");
        }

        // Get the compiled packages (which are serializable)
        final Collection<KnowledgePackage> pkgs = kbuilder.getKnowledgePackages();

        // Add the packages to a knowledgebase (deploy the knowledge packages).
        final KnowledgeBase kbase = KnowledgeBaseFactory.newKnowledgeBase();
        kbase.addKnowledgePackages(pkgs);

        final StatefulKnowledgeSession ksession = kbase.newStatefulKnowledgeSession();
        ksession.setGlobal("list", new ArrayList<Object>());

        ksession.addEventListener(new DebugAgendaEventListener());
        ksession.addEventListener(new DebugWorkingMemoryEventListener());

        // Setup the audit logging
        KnowledgeRuntimeLogger logger = KnowledgeRuntimeLoggerFactory.newFileLogger(ksession, "log/helloworld");

        final Message message = new Message();
        message.setMessage("Hello World");
        message.setStatus(Message.HELLO);
        ksession.insert(message);

        ksession.fireAllRules();
        logger.close();
        ksession.dispose();
    }

    public static void main(String[] args) throws Exception {
        
        final Rules rules = new Rules();
        rules.rules();
        
    }

} // End of the Class //
