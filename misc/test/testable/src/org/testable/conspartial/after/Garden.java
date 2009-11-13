package org.testable.conspartial.after;

import org.testable.conspartial.before.BootsWithMassiveStaticInitBlock;
import org.testable.conspartial.before.Gardener;
import org.testable.conspartial.before.Inject;
import org.testable.conspartial.before.Provides;
import org.testable.conspartial.before.Workday;


@Inject 
Garden(Gardener joe) { 
this.joe = joe; 
} 

// ... 
} 

//In the Module configuring Guice. 

@Provides 
Gardener getGardenerJoe(Workday workday, 
BootsWithMassiveStaticInitBlock badBoots) { 
Gardener joe = new Gardener(); 