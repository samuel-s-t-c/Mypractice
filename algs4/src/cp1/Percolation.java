package cp1;

import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private final WeightedQuickUnionUF uf;
    private final WeightedQuickUnionUF full;
    private int[][] grid;
    private int cntOpen;
    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) {
        if (n < 1) throw new IllegalArgumentException("Arguments less than one");
        grid = new int[n][n];
        uf = new WeightedQuickUnionUF(n*n+2);
        full = new WeightedQuickUnionUF(n*n+1);
    }

    private void check(int row, int col) {
        int len = grid.length;
        if (row < 1 || col < 1 || row > len || col > len)
            throw new IllegalArgumentException("Out of bound: "+row+" "+col);
    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        check(row, col);
        int len = grid.length;
        --row;
        --col;
        if (grid[row][col] != 0) return;

        int site = row * len + col;
        grid[row][col] = 1;
        cntOpen++;

        if (row == 0) {
            uf.union(site, len*len);
            full.union(site, len*len);
        } else if (grid[row-1][col] > 0) {
            uf.union(site, site-len);
            full.union(site, site-len);
        }
        if (row == len-1) {
            uf.union(site, len*len+1);
        }
        else if (grid[row+1][col] > 0) {
            uf.union(site, site+len);
            full.union(site, site+len);
        }
        if (col != 0 && grid[row][col-1] > 0) {
            uf.union(site, site-1);
            full.union(site, site-1);
        }
        if (col != len-1 && grid[row][col+1] > 0) {
            uf.union(site, site+1);
            full.union(site, site+1);
        }
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        check(row, col);
        return grid[row-1][col-1] != 0;
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
        check(row, col);
        int len = grid.length;
        return full.connected((row-1)*len+col-1, len*len);
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return cntOpen;
    }

    // does the system percolate?
    public boolean percolates() {
        int len = grid.length;
        return uf.connected(len*len, len*len+1);
    }

    // test client (optional)
    public static void main(String[] args){
//        int len = Integer.parseInt(args[0]);
//        cp1.Percolation p = new cp1.Percolation(len);
//        StdDraw.clear(StdDraw.BLACK);
//        StdDraw.setXscale(0, len+1);
//        StdDraw.setYscale(0, len+1);
//        while (true) {
//            int row = StdRandom.uniform(1, len+1);
//            int col = StdRandom.uniform(1, len+1);
//            if (!p.isOpen(row, col)) {
//                StdDraw.setPenColor(StdDraw.WHITE);
//                StdDraw.filledSquare(col,len-row+1,  0.45);
//                p.open(row, col);
//            }
//            if (p.percolates())
//                break;
//        }
//        StdDraw.setPenColor(StdDraw.BOOK_LIGHT_BLUE);
//        for (int row = 1; row < len+1; row++)
//            for (int col = 1; col < len+1; col++)
//                if (p.isFull(row, col))
//                    StdDraw.filledSquare(col,len-row+1,  0.45);
//        StdOut.printf("The grid percolates after %d sites opened", p.numberOfOpenSites());
//        StdOut.println("\n"+(double) p.numberOfOpenSites()/(len*len));
    }
}
