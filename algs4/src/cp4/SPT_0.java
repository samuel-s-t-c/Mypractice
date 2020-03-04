package cp4;

import edu.princeton.cs.algs4.DirectedEdge;
import edu.princeton.cs.algs4.EdgeWeightedDigraph;
import edu.princeton.cs.algs4.IndexMinPQ;

public class SPT_0 {
    private double[] distTo;
    private DirectedEdge[] edgeTo;

    public SPT_0(EdgeWeightedDigraph g, int s) {
        edgeTo = new DirectedEdge[g.E()];
        distTo = new double[g.V()];
        for (int i = 0; i < g.V(); i++) {
            distTo[i] = Double.POSITIVE_INFINITY;
        }
        distTo[s] = 0.0;
        IndexMinPQ<Double> pq = new IndexMinPQ<Double>(g.V());
        pq.insert(s, distTo[s]);
        while (!pq.isEmpty()) {
            relax(g, pq.delMin(), pq);
        }
    }
    private void relax(EdgeWeightedDigraph g, int v, IndexMinPQ<Double> pq) {
        for (DirectedEdge e: g.adj(v)) {
            int w = e.to();
            if (distTo[w] > (distTo[v] + e.weight())) {
                distTo[w] = distTo[v] + e.weight();
                edgeTo[w] = e;
                if (pq.contains(w))
                    pq.change(w, distTo[w]);
                else
                    pq.insert(w, distTo[w]);
            }
        }
    }
}
