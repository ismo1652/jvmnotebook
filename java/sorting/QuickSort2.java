// Java version of quick sort
// Berlin Brown
import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 * Best:    O(n)
 * Average: O(n * log n )
 * Worst:   O(n^2)
 */
public class QuickSort2 {
    private final Comparable<Object>[] A;
    private long ops = 0;
    private long comps = 0;
    public QuickSort2(final Comparable ar[]) { this.A = ar; }        
    protected int pidx(final int l, final int r) {
        int mi = (l + r) / 2;
        int li = l;
        if (A[li].compareTo(A[mi]) >= 0) {
            li = mi;
            mi = l;
        }
        if (A[r].compareTo(A[li]) <= 0) {
            return li;
        } else if (A[r].compareTo(A[mi]) <= 0) {
            return mi;
        }
        return r;
    }
    protected int part(final int l, final int r, final int pi) {
        final Comparable<Object> piv = A[pi];
        Comparable<Object> tmp;
        tmp = A[r];
        A[r] = A[pi];
        A[pi] = tmp;
        this.ops++;
        int store = l;
        for (int idx = l; idx < r; idx++) {
            if (compare(A[idx], piv)) {
            //if (A[idx].compareTo(piv) <= 0) {
                tmp = A[idx];
                A[idx] = A[store];
                A[store] = tmp;
                this.ops++;
                store++;
            }
            comps++;
        } // End of the for //
        tmp = A[r];
        A[r] = A[store];
        A[store] = tmp;
        this.ops++;
        return store;
    }
    /** Quick sort */
    public void $(final int l, final int r) {
        if (r <= l) {
            return;
        }
        int pi = this.pidx(l, r);
        pi = part(l, r, pi);
        this.$(l, pi - 1);
        this.$(pi + 1, r);
    }
    public Comparable[] $$() {
        this.$(0, this.A.length - 1);
        return this.A;
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

        final Integer arr[] = new Integer[list.size()];
        list.toArray(arr);
        final QuickSort2 q = new QuickSort2(arr);
        q.$$();
        for (int j = 0; j < 13; j++) {
            System.out.println("->j:" + j + " " + arr[j]);
        }
        System.out.println("Compares : " + q.comps);
    } // End of read method //   

    protected boolean compare(Comparable<Object> a, Comparable<Object> b) {
        return (a.compareTo(b) <= 0);
    }


    /** QuickSort Test Case Usage */
    public static void main(final String [] args) throws Exception {
        final Integer[] arr = {
            20, 23, 14, 3
        };
        for (final Comparable<Object> o : new QuickSort2(arr).$$()) {
            System.out.println(o);
        }
        System.out.println("+++ Larger Set");
        new QuickSort2(arr).read();
        System.out.println("Done");
    } // End of main //
} // End of the class //
