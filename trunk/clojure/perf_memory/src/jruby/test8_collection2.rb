##
##
## Simple frequency of list in ruby (jruby)
## 

require 'java'

def String.random_alphanumeric(size=16)
  # Slight difference from the other versions
  # This is alphanumeric not alpha
  s = ""
  size.times { s << (i = Kernel.rand(62); i += ((i < 10) ? 48 : ((i < 36) ? 55 : 61 ))).chr }
  s
end

def frequency(lst)
  h = Hash.new
  lst.each { |w|
    if h.has_key?(w)
      h[w] = h[w] + 1
    else
      h[w] = 1
    end
  }
  h
end

def runTest
  puts "Running jruby test"
  (1..19).each { |x|
    start1 = java.lang.System.nanoTime()
    z = 2 ** x
    puts "i-size #{z}"
    z = frequency(build_list(z, 3))  
    end1 = java.lang.System.nanoTime()
    diff = (end1 - start1) * 1e-6  
    puts "Elapsed Time: #{diff} ms"
  }
end

def build_list(n, sz)
  arr = Array.new
  (1..n).each {
    arr << String.random_alphanumeric(sz).downcase
  }
  arr
end

runTest

# End of Script # 


