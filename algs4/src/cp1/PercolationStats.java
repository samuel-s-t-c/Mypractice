package cp1;

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
    private final int t;
    private final double mean;
    private final double stddev;

    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int trials) {
        if (n < 1 || trials < 1) throw new IllegalArgumentException("Argument less than 1");
        this.t  = trials;
        double[] data = new double[trials];
        for (int i = 0; i < trials; i++) {
            Percolation p = new Percolation(n);
            while (true) {
                int row = StdRandom.uniform(1, n+1);
                int col = StdRandom.uniform(1, n+1);
                if (!p.isOpen(row, col))
                    p.open(row, col);
                if (p.percolates())
                    break;
            }
            data[i] = (double) p.numberOfOpenSites()/(n*n);
        }
        mean = StdStats.mean(data);
        stddev = StdStats.stddev(data);
    }

    // sample mean of percolation threshold
    public double mean() {
        return this.mean;
    }

    // sample standard deviation of percolation threshold
    public double stddev() {
        return this.stddev;
    }

    // low endpoint of 95% confidence interval
    public double confidenceLo() {
        return (mean - (1.96*stddev)/Math.sqrt(t));
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
        return (mean + (1.96*stddev)/Math.sqrt(t));
    }

    // test client:
    // takes two command-line arguments n and T,
    // performs T independent computational experiments (discussed above) on an n-by-n grid,
    // and prints the sample mean, sample standard deviation, and the 95% confidence interval
    // for the percolation threshold.
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int t = Integer.parseInt(args[1]);
        PercolationStats calc = new PercolationStats(n, t);
        StdOut.printf("mean                    = %f\n", calc.mean());
        StdOut.printf("stddev                  = %f\n", calc.stddev());
        StdOut.printf("95%% confidence interval = [%f, %f]\n", calc.confidenceLo(), calc.confidenceHi());
    }
}
