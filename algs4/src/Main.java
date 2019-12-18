import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Main {

    public static void main(String[] args) {
	int N = Integer.parseInt(args[0]);
	int lo = Integer.parseInt(args[1]);
	int hi = Integer.parseInt(args[2]);
	for (int i = 0; i < N; i++) {
	    int temp = (int) StdRandom.uniform(lo, hi);
        StdOut.printf("%2d\n", temp);
    }
    }
}
