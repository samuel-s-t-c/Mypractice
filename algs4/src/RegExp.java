import edu.princeton.cs.algs4.Accumulator;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.regex.Pattern;

public class RegExp {
    public static void main(String[] args) {
        int T = Integer.parseInt(args[0]);
        VisualAccumulator a = new VisualAccumulator(T, 1.0);
        for (int t = 0; t < T;t ++)
        a.addDataValue(StdRandom.uniform());
        StdOut.println(a);
    }
}
