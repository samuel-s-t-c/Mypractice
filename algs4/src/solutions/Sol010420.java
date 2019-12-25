package solutions;

public class Sol010420 {
    public static int BitonicMax(int[] a, int lo, int hi) {
      if (hi == lo) return hi;
      int mid = lo + (hi - lo) / 2;
      if (a[mid] < a[mid+1]) return BitonicMax(a, mid+1, hi);
      if (a[mid] > a[mid+1]) return BitonicMax(a, lo, mid);
      else return mid;
    }
}
