package cp2;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;

public class Insertion {
    public static void sort(Comparable[] a) {
        int len = a.length;
        int cnt = 0;
        show(a, 0, 0);
        for (int i = 1; i < len; i++) {
            int j = i;
            for (; j > 0 && less(a[j], a[j-1]); j--) {
                exch(a, j, j-1);
                cnt++;
            }
            show(a, i, j);
        }
    }

    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }
    private static void exch(Comparable[] a, int i, int j) {
        Comparable t = a[i]; a[i] = a[j]; a[j] = t;
    }

    private static int cnt = 0;
    private static void show(Comparable[] a) {
        for (int i = 0; i < a.length; i++) {
            StdOut.print(a[i] + " ");
        }
        StdOut.println();
    }
    private static void show(Comparable[] a, int h, int j) {
        cnt++;
        StdDraw.setPenColor(StdDraw.GRAY);
        for (int i = 0; i < a.length; i++) {
            double tmp = (double)a[i].toString().toCharArray()[0];
            if (i > h)
                StdDraw.setPenColor(StdDraw.GRAY);
            else if (i > j)
                StdDraw.setPenColor(StdDraw.BLACK);
            else if (i == j)
                StdDraw.setPenColor(StdDraw.BOOK_RED);
            StdDraw.filledRectangle(i, cnt-tmp/200, 0.3, tmp/200);
        }
    }

    public static boolean isSorted(Comparable[] a) {
        for (int i = 1; i < a.length; i++) {
            if (less(a[i], a[i-1]))
                return false;
        }
        return true;
    }
    public static void main(String[] args) {
        //String[] a = In.readStrings();
        Character[] a = {'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
        StdDraw.setCanvasSize(1024, 4096);
        StdDraw.setXscale(-1, a.length);
        StdDraw.setYscale(15, 0);
        sort(a);
        assert isSorted(a);
        show(a,-1, -1);
    }
}
