import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class LinkedStack<Item> implements Iterable<Item> {
    public static void main(String[] args)
    {
        LinkedStack<String> stack = new LinkedStack<String>();
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (!item.equals("-"))
                stack.push(item);
            else if (!stack.isEmpty()) StdOut.print(stack.pop()+" ");
        }
        StdOut.println();
        StdOut.print("("+ stack.size()+" left on stack:L");
        for (String s: stack)
            StdOut.print(" "+s);
        StdOut.println(")");
    }

    private Node first;
    private int N;

    private class Node
    {
        Item item;
        Node next;
    }

    public void push(Item item)
    {
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
        N++;
    }

    public Item pop()
    {
        if (isEmpty())
            throw new NoSuchElementException();
        Item ret = first.item;
        first = first.next;
        N--;
        return ret;
    }

    public boolean isEmpty()
    {
        return N == 0;
    }

    public int size()
    {
        return N;
    }

    private class ReverseIterator implements Iterator<Item>
    {
        private Node i = first;
        @Override
        public boolean hasNext()
        {
            return i != null;
        }

        @Override
        public void remove()
        {
            throw new UnsupportedOperationException();
        }

        @Override
        public Item next() {
            if (i == null)
                throw new NoSuchElementException();
            Item ret = i.item;
            i = i.next;
            return ret;
        }
    }

    @Override
    public Iterator<Item> iterator()
    {
        return new ReverseIterator();
    }
}
