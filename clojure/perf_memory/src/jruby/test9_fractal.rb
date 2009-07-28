##
## Example Mandelbrot Example
## Slightly Different from the java and clojure versions:
##
## From: http://warp.povusers.org/MandScripts/ruby.html
##

require 'java'

def mandelbrot

  cols,lines   = 79, 30
  minre,minim  = -2.0, -1.0
  maxre,maxim  =  1.0,  1.0
  chars   = ' .,-:/=HOAM%&$#@_'
  maxiter = chars.length-1

  im=minim
  lines.times do |y|
    re=minre
    cols.times do |x|
      zr,zi = re,im
      n=0
      maxiter.times do |n|
        a,b = zr*zr, zi*zi
        break if a+b > 4.0
        zr,zi = a-b+re, 2*zr*zi+im
        n += 1
      end

      #print chars.slice(n,1)
      re += (maxre-minre)/cols
    end
    im += (maxim-minim)/lines
    #puts
  end

end

def runTest
  start1 = java.lang.System.nanoTime()
  mandelbrot
  end1 = java.lang.System.nanoTime()
  diff = (end1 - start1) * 1e-6  
  puts "Elapsed Time: #{diff} ms"
end

runTest

# End of Script
