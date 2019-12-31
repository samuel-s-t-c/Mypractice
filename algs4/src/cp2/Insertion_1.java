package cp2;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class Insertion_1 {
    public static void sort(Comparable[] a) {
        int len = a.length;
        int cnt = 0;
        for (int i = 1; i < len; i++) {
            int j = i-1;
            for (; j >= 0 && less(a[i], a[j]); j--) {
                //exch(a, j, j-1);
                cnt++;
            }
            Comparable tmp = a[i];
            for (int x = i; x > j+1; x--) {
                move(a, x-1, x);
            }
            a[j+1] = tmp;
        }
    }
    private static void move(Comparable[] a, int i, int j) {
        a[j] = a[i];
    }
    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }
    private static void exch(Comparable[] a, int i, int j) {
        Comparable t = a[i]; a[i] = a[j]; a[j] = t;
    }

    private static void show(Comparable[] a) {
        for (int i = 0; i < a.length; i++) {
            StdOut.print(a[i] + " ");
        }
        StdOut.println();
    }
    public static boolean isSorted(Comparable[] a) {
        for (int i = 1; i < a.length; i++) {
            if (less(a[i], a[i-1]))
                return false;
        }
        return true;
    }
    public static void main(String[] args) {
        String[] a = In.readStrings();
        sort(a);
        assert isSorted(a);
        show(a);
    }
}
