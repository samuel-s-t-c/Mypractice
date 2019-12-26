import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private WeightedQuickUnionUF uf;
    private int[][] grid;
    private int cntOpen;
    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) {
        if (n < 1) throw new IllegalArgumentException("Arguments less than one");
        grid = new int[n][n];
        uf = new WeightedQuickUnionUF(n*n + 2);
    }
    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        int len = grid.length;
        if (row < 1 || col < 1 || row > len || col > len)
            throw new IllegalArgumentException("Out of bound");
        grid[--row][--col] = 1;
        cntOpen++;
        int up, down, left, right;
        int site = row * len + col;
        if (row == 0) {
            up = len * len;
            down = site + row;
        }
        else if (row == len - 1) {
            up = site - row;
            down = len * len + 1;
        } else {
            up = site - row;
            down = site + row;
        }
        if (col == 0) {
            left = site;
            right = site + 1;
        } else if (col == len -1) {
            left = site - 1;
            right = site;
        } else {
            left = site - 1;
            right = site + 1;
        }
        if (!uf.connected(site, up))
            uf.union(site, up);
        if (!uf.connected(site, down))
            uf.union(site, down);
        if (!uf.connected(site, left))
           uf.union(site, left);
        if (!uf.connected(site, right))
           uf.union(site, right);

    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        return grid[row - 1][col -1 ] == 1;
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
        int len = grid.length;
        return uf.connected((row-1)*len+col-1, len*len);
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return cntOpen;
    }

    // does the system percolate?
    public boolean percolates() {
        int len = grid.length;
        int vsite = len*len;
        return uf.connected(vsite, vsite+1);
    }

    // test client (optional)
    public static void main(String[] args) {
        int len = 200;
        Percolation p = new Percolation(len);
        p.open(2,1);
        StdOut.println(p.isFull(2,1));
        p.open(1,1);
        StdOut.println(p.isFull(2,1));
//        while (true) {
//            int row = StdRandom.uniform(1, len+1);
//            int col = StdRandom.uniform(1, len
//                    +1);
//            if (!p.isOpen(row, col))
//                p.open(row,col);
//            if (p.percolates())
//                break;
//        }
//        StdOut.printf("The grid percolates after %d sites opened",p.numberOfOpenSites());
//        StdOut.println("\n"+(double)p.numberOfOpenSites()/(len*len));
    }
}
