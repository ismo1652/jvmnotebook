#!/usr/bin/perl -w

# Process java sources files
# Berlin Brown

use File::Copy;

# Create a list of all files in the current directory
opendir(DIR, "./target/sources");

@files = grep(/\.jar$/, readdir(DIR));
closedir(DIR);

# Print all the filenames in our array
print "{SCRIPT} begin processing";
foreach $file (@files) {
   print "{SCRIPT} Counting source ./target/sources/$file\n";   
   system "perl", "cloc-1.53.pl", "./target/sources/$file.dir/";   
   print "{SCRIPT} DONE\n";
}

# End of script