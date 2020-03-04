package cp3;

import java.util.concurrent.BlockingDeque;

public class RedBlackBST<Key extends Comparable<Key>, Value> {
    private static boolean RED = true;
    private static boolean BLACK = false;
    private Node root;
    private class Node {
        public Key key;
        public Value val;
        public Node left, right;
        public int N;
        public boolean color;
        public Node(Key key, Value val, int N, boolean color) {
            this.key = key;
            this.val = val;
            this.N = N;
            this.color = color;
        }
    }

    private boolean isRED(Node x) {
        if (x == null) return false;
        return x.color == RED;
    }
    private boolean isBLACK(Node x) {
        if (x == null) return true;
        return x.color == BLACK;
    }
    private int size(Node x) {
        return x.N;
    }
    private Node rotateLeft(Node h) {
        Node x = h.right;
        h.right = x.left;
        x.left = h;
        x.color = h.color;
        h.color = RED;
        x.N = h.N;
        h.N = 1 + size(h.left) + size(h.right);
        return x;
    }
    private Node rotateRight(Node h) {
        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = h.color;
        h.color = RED;
        x.N = h.N;
        h.N = 1 + size(h.left) + size(h.right);
        return x;
    }
    private void flipColors(Node h) {
        h.color = RED;
        h.left.color = h.right.color =  BLACK;
    }

//    public void put(Key key, Value val) {
//        root = put(root, key, val);
//        root.color = BLACK;
//    }
//    private Node put(Node h, Key key, Value val) {
//        if (h == null)
//            return new Node(key, val, 1, RED);
//        int cmp = key.compareTo(h.key);
//        if (cmp < 0)
//            h.left = put(h.left, key, val);
//        else if (cmp > 0)
//            h.right = put(h.right, key, val);
//        else
//            h.val = val;
//
//        if (isRED(h.right) && isBLACK(h.left)) h = rotateLeft(h);
//        if (isRED(h.left) && isRED(h.left.left)) h= rotateRight(h);
//        if (isRED(h.left) && isRED(h.right)) flipColors(h);
//    }
}
