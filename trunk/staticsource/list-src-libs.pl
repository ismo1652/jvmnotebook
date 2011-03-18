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
   print "{SCRIPT} Extracting ./target/sources/$file\n";
   mkdir "./target/sources/$file.dir";
   copy "./target/sources/$file", "./target/sources/$file.dir/$file" ;
   
   chdir("./target/sources/$file.dir") or die "{SCRIPT} ERROR, cannot chdir $!";
   system "jar", "-xvf", "$file";
   chdir("../../..") or die "{SCRIPT} ERROR, return to directory $!";
   print "{SCRIPT} DONE\n";
}

# End of script