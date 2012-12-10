/* Arrays.java -- Utility class with methods to operate on arrays
   Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007,
   Free Software Foundation, Inc.

This file is part of GNU Classpath.

GNU Classpath is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Classpath is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Classpath; see the file COPYING.  If not, write to the
Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301 USA.

Linking this library statically or dynamically with other modules is
making a combined work based on this library.  Thus, the terms and
conditions of the GNU General Public License cover the whole
combination.

As a special exception, the copyright holders of this library give you
permission to link this library with independent modules to produce an
executable, regardless of the license terms of these independent
modules, and to copy and distribute the resulting executable under
terms of your choice, provided that you also meet, for each linked
independent module, the terms and conditions of the license of that
module.  An independent module is a module which is not derived from
or based on this library.  If you modify this library, you may extend
this exception to your version of the library, but you are not
obligated to do so.  If you do not wish to do so, delete this
exception statement from your version.
 */

package TEST.algo;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 * A look at the quick sort/sort algorithms from GNU classpath.
 * 
 * @author berlin brown 
 */
public class TestSort {
    
    private int comps = 0;
    
    public static void main(final String [] args) throws Exception {
        System.out.println("Testing");
        final int [] a = new int [] {
                12, 
                3, 
                9,
                23,
                55, 
                2                
        };        
        System.out.println("Done");
        final TestSort t = new TestSort();        
        t.sort(a);
        for (int i = 0; i < a.length; i++) {
            System.out.println("-]" + a[i]);
        }
        
        //////
        final TestSort tt = new TestSort();
        tt.read();
        
    } // End of the method main //
    
    // 23(11) P. 1249-1265 (November 1993). This algorithm gives n*log(n)
    // performance on many arrays that would take quadratic time with a standard
    // quicksort.

    public void sort(final int [] a) {
        sort(a, 0, a.length);
    } // End of the method //
    
    /**
     * Performs a stable sort on the elements, arranging them according to their
     * natural order.
     */
    public void sort(final int[] a, int fromIndex, int toIndex) {
        if (fromIndex > toIndex) {
            throw new IllegalArgumentException();
        }
        if (fromIndex < 0) {
            throw new ArrayIndexOutOfBoundsException();
        }
        qsort(a, fromIndex, toIndex - fromIndex);
    }

    /**
     * Performs a recursive modified quicksort.
     */
    protected void qsort(int[] array, int from, int count) {
        // Use an insertion sort on small arrays.
        if (count <= 7) {
            for (int i = from + 1; i < from + count; i++)
                for (int j = i; j > from && array[j - 1] > array[j]; j--)
                    swap(j, j - 1, array);
            return;
        }
        // Determine a good median element.
        int mid = from + count / 2;
        int lo = from;
        int hi = from + count - 1;
        if (count > 40) { // big arrays, pseudomedian of 9
            int s = count / 8;
            lo = med3(lo, lo + s, lo + 2 * s, array);
            mid = med3(mid - s, mid, mid + s, array);
            hi = med3(hi - 2 * s, hi - s, hi, array);
        }
        mid = med3(lo, mid, hi, array);
        int a, b, c, d;
        int comp;
        // Pull the median element out of the fray, and use it as a pivot.
        swap(from, mid, array);
        a = b = from;
        c = d = from + count - 1;
        // Repeatedly move b and c to each other, swapping elements so
        // that all elements before index b are less than the pivot, and all
        // elements after index c are greater than the pivot. a and b track
        // the elements equal to the pivot.
        while (true) {
            while (b <= c && (comp = compare(array[b], array[from])) <= 0) {
                if (comp == 0) {
                    swap(a, b, array);
                    a++;
                }
                b++;
            }
            while (c >= b && (comp = compare(array[c], array[from])) >= 0) {
                if (comp == 0) {
                    swap(c, d, array);
                    d--;
                }
                c--;
            }
            if (b > c)
                break;
            swap(b, c, array);
            b++;
            c--;
        }
        // Swap pivot(s) back in place, the recurse on left and right sections.
        hi = from + count;
        int span;
        span = Math.min(a - from, b - a);
        vecswap(from, b - span, span, array);

        span = Math.min(d - c, hi - d - 1);
        vecswap(b, hi - span, span, array);

        span = b - a;
        if (span > 1)
            qsort(array, from, span);

        span = d - c;
        if (span > 1)
            qsort(array, hi - span, span);
    } // End of the method //

    /**
     * Swaps the elements at two locations of an array
     */
    protected void swap(int i, int j, int[] a) {
        int c = a[i];
        a[i] = a[j];
        a[j] = c;
    }

    /**
     * Swaps two ranges of an array.
     */
    protected void vecswap(int i, int j, int n, int[] a) {
        for (; n > 0; i++, j++, n--)
            swap(i, j, a);
    }

    /**
     * Finds the index of the median of three array elements.     
     */
    protected int med3(int a, int b, int c, int[] d) {
      return (d[a] < d[b]
              ? (d[b] < d[c] ? b : d[a] < d[c] ? c : a)
              : (d[b] > d[c] ? b : d[a] > d[c] ? c : a));
    }
    
    /**
     * Compares two integers in natural order, since a - b is inadequate.
     */
    protected int compare(final int a, final int b) {
        comps++;
        return (a < b) ? -1 : (a == b) ? 0 : 1;
    }
    
    public void read() throws Exception {
        final List<Integer> list = new ArrayList<Integer>();
        final FileInputStream stream = new FileInputStream("./numbers.dat");
        final BufferedReader reader = new BufferedReader(new InputStreamReader(stream));
        String data = "";
        try {
            do {
                data = reader.readLine();
                if (data != null) {
                    final int i = Integer.parseInt(data.trim());
                    list.add(i);
                } // End of the if //
            } while(data != null);
        } catch(final Exception e) {
            e.printStackTrace();
        } finally {
            if (stream != null) {
                try {
                stream.close();
                } catch(Exception ee) { }
            }
        }        
        final int [] arr = toint(list);
        sort(arr);
        for (int j = 0; j < 13; j++) {
            System.out.println("->j:" + j + " " + arr[j]);
        }
        System.out.println("Compares : " + comps);
    } // End of read method //
    
    protected int[] toint(final List<Integer> integers) {
        int[] ret = new int[integers.size()];
        for (int i=0; i < ret.length; i++)
        {
            ret[i] = integers.get(i).intValue();
        }
        return ret;
    }
    
} // End of the class //
