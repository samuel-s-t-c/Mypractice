package cp3;

import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class ssst<Key, Value> {
    private Node first = null;
    private int size = 0;
    private class Node {
        Key key;
        Value val;
        Node next;
        Node(Key key, Value val, Node next) {
            this.key = key;
            this.val = val;
            this.next = next;
        }
    }
    public ssst() {    }
    public Value get(Key key) {
        for (Node f = first; f != null; f = f.next) {
            if (key.equals(f.key))
                return f.val;
        }
        return null;
    }

    public void put(Key key, Value val) {
        for (Node f = first; f != null; f = f.next) {
            if (key.equals(f.key)) {
                f.val = val;
                size++;
                return;
            }
        }
        first = new Node(key, val, first);
        size++;
    }

    public void delete(Key key) {
        Node prev = null;
        for (Node f = first; f != null; f = f.next) {
            if (key.equals(f.key)) {
                if (prev != null)
                    prev.next = f.next;
                f.next = null;
                size--;
                return;
            }
            prev = f;
        }
    }

    public int size() {
        return this.size;
    }

    public Iterable<Key> keys() {
        Queue<Key> queue = new Queue<>();
        for (Node x = first; x != null; x = x.next) {
            queue.enqueue(x.key);
        }
        return queue;
    }

    public static void main(String[] args) {
        ssst<String, Integer> st = new ssst<>();
        for (int i = 0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }
        for (String s : st.keys())
            StdOut.println(s + " " + st.get(s));
    }
}
