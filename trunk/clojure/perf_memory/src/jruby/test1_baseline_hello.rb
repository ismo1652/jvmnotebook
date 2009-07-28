##
##
## Simple baseline hello world test in jruby
## 

require 'java'

def helloWorldBaseline
  # Run the application
  start1 = java.lang.System.nanoTime()
  arr = Array.new
  (1..1000000).each {
    res = 2.2 * 4.1 * 5.4
  }
  end1 = java.lang.System.nanoTime()
  diff = (end1 - start1) * 1e-6  
  puts "Elapsed Time: #{diff} ms"
end

helloWorldBaseline

# End of Script # 


