import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Arrays;

public class ThreeSum3 {
    public static int count(int[] a) {
        Arrays.sort(a);
        int len = a.length;
        int cnt = 0;
        for (int i = 0; i < len - 2; i++) {
            int j = i + 1;
            int k = len - 1;
            while (j < k) {
                int sum = a[i] + a[j] + a[k];
                if (sum == 0)
                    cnt++;
                if (sum > 0)
                    k--;
                else
                    j++;
            }
        }
        return cnt;
    }

    private static boolean trial(int N) {
        int MAX = 2000000;
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = StdRandom.uniform(-MAX, MAX);

        }
        int isRepeated = 0;
        int[] b = new int[N];
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (a[i] == a[j]) {
                    b[isRepeated] = a[i];
                    isRepeated++;
                }
            }
        }
        StdOut.println("Repeated numbers have "+isRepeated);
        for (int i = 0; i < isRepeated; i++) {
            StdOut.print(b[i]+" ");
        }
        StdOut.println();
        double prev, now;
        StopwatchMy timer = new StopwatchMy();
        int cnt0 = ThreeSum.count(a);
        prev = timer.elapseTime();
        StdOut.printf("ThreeSumN: %d time: %.5f\n", cnt0, prev);
        int cnt1 = ThreeSumFast.count(a);
        now = timer.elapseTime();
        StdOut.printf("ThreeSumF: %d time: %.5f\n", cnt1, (now - prev));
        int cnt2 = ThreeSum3.count(a);
        prev = now;
        now = timer.elapseTime();
        StdOut.printf("ThreeSum3: %d time: %.5f\n\n", cnt2, (now-prev));
        return cnt2 == cnt1;
    }

    public static void main(String[] args) {
        for (int N = 250; true; N = N) {
            trial(8*N);
        }
    }
}
