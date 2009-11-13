package org.testable.conspartial.before;

//SUT initializes collaborators. This prevents 
//tests and users of Garden from altering them. 

class Garden { 
Garden(Gardener joe) { 
joe.setWorkday(new TwelveHourWorkday()); 
joe.setBoots( 
  new BootsWithMassiveStaticInitBlock()); 
this.joe = joe; 
} 

// ... 
} 

