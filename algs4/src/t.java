import edu.princeton.cs.algs4.*;

public class t {
    public static void main(String[] args) {
        int cnt = 0;
        int n = 10;
        int[] std = new int[n];
        int[] input = new int[n];
        for (int i = 0; i < n; i++) {
            std[i] = i;
        }

        for (int i = 0; i < n; i++) {
            input[i] = std[n-i-1];
        }

        for (int i = 1; i < n; i++) {
            int i1, i2;
            int j = i;
            i2 = indexof(std, input[i]);
            while (true) {
                i1 = indexof(std, input[--j]);
                if (i1 > i2) {
                    exch(input, j, j+1);
                    cnt++;
                }
                if (j == 0 || i1 < i2) {
                    break;
                }
            }
        }
        for(int i : input) {
            StdOut.print(i+" ");
        }
        StdOut.println("\ncnt is "+cnt);
    }
    public static void exch(int[] a, int i, int j) {
        if (a == null) return;
        int temp = a[i]; a[i] = a[j]; a[j] = temp;
    }
    public static int indexof(int[] a, int val) {
        if (a == null) return -1;
        int len = a.length;
        for (int i = 0; i < len; i++) {
            if (a[i] == val)
                return i;
        }
        return -1;
    }
}
