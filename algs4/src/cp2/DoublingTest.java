package cp2;

import edu.princeton.cs.algs4.*;

import java.util.Arrays;

public class DoublingTest {
    public static void main(String[] args) {
        String alg1 = args[0];
        String alg2 = args[1];
        String alg3 = args[2];
        int n = Integer.parseInt(args[3]);
        int t = Integer.parseInt(args[4]);
        double cnt1 = 0, cnt2 = 0, cnt3 = 0;
        while (true) {

            cnt1 = SortCompare_my.timeRandomInput(alg1, n, t);
            cnt2 = SortCompare_my.timeRandomInput(alg2, n, t);
            cnt3 = SortCompare_my.timeRandomInput(alg3, n, t);

            StdOut.printf("For %d random Doubles: \n %-10s %-10s %-10s %-10s %-10s \n"
                    , n, "Algorithm", "TIME", "Ratio(1)","Ratio(2)","Ratio(3)");
            StdOut.printf("1 %-10s %-10f %-10f %-10f %-10f\n", alg1, cnt1, cnt1/cnt1, cnt2/cnt1, cnt3/cnt1);
            StdOut.printf("2 %-10s %-10f %-10f %-10f %-10f\n", alg2, cnt2, cnt1/cnt2, cnt2/cnt2, cnt3/cnt2);
            StdOut.printf("3 %-10s %-10f %-10f %-10f %-10f\n\n", alg3, cnt3, cnt1/cnt3, cnt2/cnt3, cnt3/cnt3);
            n *= 2;
        }
    }
    public static double time(String alg, Double[] a) {
        Stopwatch sw = new Stopwatch();
        if      (alg.equals("Insertion"))       Insertion.sort(a);
        else if (alg.equals("InsertionX"))      InsertionX.sort(a);
        else if (alg.equals("BinaryInsertion")) BinaryInsertion.sort(a);
        else if (alg.equals("Selection"))       Selection.sort(a);
            // else if (alg.equals("Bubble"))          Bubble.sort(a);
        else if (alg.equals("Shell"))           Shell.sort(a);
        else if (alg.equals("Merge"))           Merge.sort(a);
        else if (alg.equals("MergeX"))          MergeX.sort(a);
        else if (alg.equals("MergeBU"))         MergeBU.sort(a);
        else if (alg.equals("Quick"))           Quick.sort(a);
        else if (alg.equals("Quick3way"))       Quick3way.sort(a);
        else if (alg.equals("QuickX"))          QuickX.sort(a);
        else if (alg.equals("Heap"))            Heap.sort(a);
        else if (alg.equals("System"))          Arrays.sort(a);
        else throw new IllegalArgumentException("Invalid algorithm: " + alg);
        return sw.elapsedTime();
    }
}
