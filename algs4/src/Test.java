import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Test {
    public static void main(String[] args) {
        for (int n = 0; n < 10; n++)
            StdOut.print(fib(n)+" ");
        int n, p;
        int[] arr = {1,2};
        while ((n = arr[0]) != p)
            p = n;
    }

    public static int fib(int n) {
        if (n < 2)
            return n;
        else
            return fib(n-2) + fib(n-1);
    }
}
