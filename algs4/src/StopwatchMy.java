import edu.princeton.cs.algs4.StdRandom;

public class StopwatchMy {
    private final long time;
    public StopwatchMy() {
        this.time = System.currentTimeMillis();
    }
    public double elapseTime() {
        long time = System.currentTimeMillis();
        return (time - this.time)/1000.0;
    }

    public static void main(String[] args) throws Exception {
        int N = Integer.parseInt(args[0]);
        int[] a = new int[N];
        for (int i = 0; i < N; i++)
            a[i] = StdRandom.uniform(-1000000, 1000000);
        StopwatchMy start = new StopwatchMy();
        int cnt = ThreeSum.count(a);
        double time = start.elapseTime();
        System.out.println(cnt + " triples " + time + " seconds");
    }
}
