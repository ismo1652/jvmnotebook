##
##
## http://rosettacode.org/wiki/Quicksort#Ruby
## Ruby example from rosetta code
## Simple quick sort
## start=Time.new;y=0;(1..2000000).each { |x| y=x };Time.new - start
##

require 'java'

class Array
  def quick_sort
    return self if length <= 1
    pivot = self[length / 2]
    return (find_all { |i| i <  pivot }).quick_sort +
           (find_all { |i| i == pivot }) +
           (find_all { |i| i >  pivot }).quick_sort
  end
end

def runTest1a(n)
  # Run the application
  start1 = java.lang.System.nanoTime()
  arr = Array.new
  (1..n).each {
    arr << rand(100000)
  }
  res = arr.quick_sort

  end1 = java.lang.System.nanoTime()
  diff = (end1 - start1) * 1e-6  
  puts "Elapsed Time: #{diff} ms"
end

runTest1a(81)
runTest1a(243)
runTest1a(729)
runTest1a(2187)
runTest1a(6561)
runTest1a(19683)
runTest1a(59049)
runTest1a(177147)

# End of Script # 


