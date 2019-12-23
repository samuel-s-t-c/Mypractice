import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class RegExp {
    public static void main(String[] args) {
        int T = Integer.parseInt(args[0]);
        VisualAccumulatorMy a = new VisualAccumulatorMy(T, 1.0);
        for (int t = 0; t < T;t ++)
        a.addDataValue(StdRandom.uniform());
        StdOut.println(a);
    }
}
