package solutions;

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.UF;

public class Successor {
    private int[] max;
    private UF uf;

    public Successor(int n) {
        max = new int[n];
        for (int i = 0; i < n; i++) {
            max[i] = i;
        }
        uf = new UF(n);
    }

    public boolean remove(int n) {
        if (n == max.length - 1 || uf.connected(n, n+1)) return false;
        int prev = max[uf.find(n+1)];
        uf.union(n, n+1);
        int root = uf.find(n);
        max[root] = (n+1) > prev ? (n+1):prev;
        return true;
    }

    public int getSuccessor(int n) {
        return max[uf.find(n)];
    }

    public static void main(String[] args) {
        Successor s = new Successor(10);
        StdOut.println("s.remove(4):"+s.remove(4));
        StdOut.println("s.getSuccessor(4):"+s.getSuccessor(4));
        StdOut.println("s.remove(6):"+s.remove(6));
        StdOut.println("s.getSuccessor(6):"+s.getSuccessor(6));
        StdOut.println("s.remove(5):"+s.remove(5));
        StdOut.println("s.getSuccessor(4):"+s.getSuccessor(4));
        StdOut.println("s.getSuccessor(5):"+s.getSuccessor(5));
        StdOut.println("s.getSuccessor(6):"+s.getSuccessor(6));
    }
}
