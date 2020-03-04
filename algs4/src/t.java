import edu.princeton.cs.algs4.StdOut;

import java.util.Arrays;

class t {
    public static void main(String[] args) {
        StdOut.println(lengthOfLongestSubstring(args[0]));
    }
    public static  int lengthOfLongestSubstring(String s) {
        if (s == null) return 0;
        int len = s.length();
        char[] arr = new char[len];
        arr[0] = s.charAt(0);
        int head = 0, lenOfLongest = 1;
        int i;
        for (i = 1; i < len; i++) {
            arr[i] = s.charAt(i);
            char c = arr[i];
            int currLen = i - head;
            StdOut.println(Arrays.toString(arr));
            for (int j = i; j > head; j--) {
                int cmp = arr[j] - arr[j-1];
                if (cmp == 0) {
                    lenOfLongest = Math.max(currLen, lenOfLongest);
                    arr[i] = c;
                    head = i;
                    break;
                } else if (cmp < 0) {
                    char tmp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = tmp;
                }
            }
        }
        StdOut.println(Arrays.toString(arr));
        lenOfLongest = Math.max((i - head), lenOfLongest);
        return lenOfLongest;
    }
}
