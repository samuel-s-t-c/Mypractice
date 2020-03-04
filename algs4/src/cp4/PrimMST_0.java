package cp4;

import edu.princeton.cs.algs4.Edge;
import edu.princeton.cs.algs4.EdgeWeightedGraph;
import edu.princeton.cs.algs4.IndexMinPQ;
import edu.princeton.cs.algs4.Queue;

public class PrimMST_0 {
    private IndexMinPQ<Double> pq;
    private Edge[] edgeTo;
    private double[] distTo;
    private boolean[] marked;
    private double weight;

    public PrimMST_0(EdgeWeightedGraph g) {
        marked = new boolean[g.V()];
        edgeTo = new Edge[g.V()];
        distTo = new double[g.V()];
        for (int v = 0; v < g.V(); v++) {
            distTo[v] = Double.POSITIVE_INFINITY;
        }
        pq = new IndexMinPQ<>(g.V());
        distTo[0] = 0.0;
        pq.insert(0, 0.0);
        while (!pq.isEmpty()) {
            visit(g, pq.delMin());
        }
    }
    private void visit(EdgeWeightedGraph g, int index) {
        marked[index] = true;
        for (Edge e : g.adj(index)) {
            int w = e.other(index);
            if (marked[w]) continue;
            if (e.weight() < distTo[w]) {
                edgeTo[w] = e;
                distTo[w] = e.weight();
                if (pq.contains(w)) pq.change(w, distTo[w]);
                else pq.insert(w, distTo[w]);
            }
        }
    }

    public Iterable<Edge> edges() {
        Queue<Edge> mst = new Queue<>();
        for (int v = 0; v < edgeTo.length; v++) {
            Edge e = edgeTo[v];
            if (e != null)
                mst.enqueue(e);
        }
        return mst;
    }
    public double weight() {
        double ret = 0;
        for (double d : distTo) {
            ret += d;
        }
        return ret;
    }
}
