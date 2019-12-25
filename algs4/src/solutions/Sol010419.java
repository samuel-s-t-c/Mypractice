package solutions;

public class Sol010419 {
    private Sol010419(){}
    public static int min(int[] a) {
        int len = a.length;
        int min = 0;
        for (int n = 0; n != len; n++) {
            if (a[n] < a[min])
                min = n;
        }
        return min;
    }
    public static int[] find1(int[][] a, int lo, int hi) {
        if (hi == lo) return new int[]{hi,min(a[hi])};
        int mid = lo + (hi - lo)/2;
        int mininma = min(a[mid]);
        if (a[mid][mininma] > a[mid+1][mininma]) return find1(a, mid+1, hi);
        if (a[mid][mininma] < a[mid+1][mininma]) return find1(a, lo, mid);
        else return new int[]{mid, min(a[hi])};
    }
    public static int[] find2(int[][] a) {
        int len = a.length;
        int lo = 0;
        int hi = len-1;
        int row, col;
        while (true) {
            row = lo + (hi - lo)/2;
            col = 0;

            for (int n = 0; n < len; n++) {
                if (a[row][n] < a[row][col])
                    col = n;
            }
            if (row != lo && a[row][col] > a[row - 1][col]) {
                hi = row;
                continue;
            }
            if (row != hi && a[row][col] > a[row + 1][col]) {
                lo = row + 1;
                continue;
            }
            break;
        }
        return new int[]{row, col};
    }
    public static void main(String[] args) {
        int[][] a = {
                {11, 10, 17, 12},
                {5, 2, 3, 4},
                {1, 15, 7, 8},
                {13, 14, 6, 16}
        };
        int[] b = find2(a);
        int[] c = find1(a, 0, 3);
        System.out.println("row: "+b[0]+" col: "+b[1]);
        System.out.println("row: "+c[0]+" col: "+c[1]);
    }
}
