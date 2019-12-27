import edu.princeton.cs.algs4.StdDraw;

public class TestStdDraw {
    public static void main(String[] args) {
        int len = 10;
        StdDraw.setXscale(1,len+1);
        StdDraw.setYscale(1,len+1);
        StdDraw.clear(StdDraw.BLACK);
        StdDraw.setPenColor(StdDraw.WHITE);
        for (int i = 1; i < (len+1); i++) {
            StdDraw.line(1, i, len+1, i);
        }
    }

}
