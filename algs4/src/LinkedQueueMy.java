import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class LinkedQueueMy<Item> implements Iterable<Item> {
    public static void main(String[] args) {
        LinkedQueueMy<Integer> test = new LinkedQueueMy<Integer>();
        if (test.isEmpty())
            for (int i = 0; i < 10; i++) {
                test.enqueue(i);
            }
        test.debug();
        StdOut.println();
        int size = test.size();
        for (int i = 0; i < size; i++) {
            StdOut.print(test.dequeue()+" ");
        }
        StdOut.println();
        for (int i = 0; i < 12; i++) {
            test.enqueue(i);
            test.enqueue(i);
            test.dequeue();
        }
        test.debug();
        for (int i : test)
            StdOut.print(i+" ");
    }
    private void debug()
    {
        Node node = first;
        for (int i = 0; i < N; i++) {
            StdOut.print(node.item + " ");
            node = node.next;
        }
        StdOut.println();
    }

    public Iterator<Item> iterator()
    {
        return new OrderedIterator();
    }
    private  class OrderedIterator implements Iterator<Item>
    {
        private Node i = first;
        @Override
        public Item next() {
            if (i == null)
                throw  new NoSuchElementException();
            Item ret = i.item;
            i = i.next;
            return ret;
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }

        @Override
        public boolean hasNext() {
            return i != null;
        }
    }
    private class Node {
        Item item;
        Node next;
    }
    private Node first;
    private Node last;
    private int N;

    public void enqueue(Item item)
    {
        Node prev = last;
        last = new Node();
        last.item = item;
        last.next = null;
        if (isEmpty())
            first = last;
        else
            prev.next = last;
        N++;
    }

    public Item dequeue()
    {
        if (N == 0)
            throw new NoSuchElementException();
        Item ret = first.item;
        first = first.next;
        if (isEmpty()) last = null;
        N--;
        return ret;
    }
    public boolean isEmpty()
    {
        return first == null;
    }
    public int size()
    {
        return N;
    }
}
