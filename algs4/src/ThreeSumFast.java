import edu.princeton.cs.algs4.BinarySearch;

import java.util.Arrays;

public class ThreeSumFast {
    public static int count(int[] a) {
        Arrays.sort(a);
        int n = a.length;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (BinarySearch.rank(-(a[i] + a[j]), a) > j)
                    count++;
            }
        }
        return count;
    }
}
