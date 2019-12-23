import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ResizingArrayQueueMy<Item> implements Iterable<Item> {
    private Item[] items = (Item[]) new Object[2];
    private int head = 0;
    private int tail = 0;

    private void debug()
    {
        for (int i = 0; i <= items.length; i++)
            StdOut.printf("%-4d ", i);
        StdOut.println();
        for (int i = 0; i < items.length; i++)
            StdOut.printf("%-4d ", items[i]);
        StdOut.println();
        for (int i = 0; i <= items.length; i++)
        {
            if (i == head && i == tail)
                StdOut.print("&&&&&");
            else if (i == head)
                StdOut.print("*****");
            else if (i == tail)
                StdOut.print("^^^^^");
            else
                StdOut.print("     ");
        }
        StdOut.println("\n");
    }
    private void resize(int size)
    {
        Item[] temp = (Item[]) new Object[size];
        int len = items.length;
        for (int i = head, index = head; i != tail; i++)
        {
            if ( i == len)
            {
                i = 0;
                index = head - len;
            }
            temp[i - index] = items[i];
        }
        tail = size();
        head = 0;
        items = temp;
    }

    public void enqueue(Item item)
    {
        int temp = tail - head;
        if (temp == -1 || temp == items.length - 1)
            resize(2 * items.length);
        if (tail == items.length) tail = 0;
        items[tail++] = item;
    }

    public Item dequeue()
    {
        if (size() <= items.length/4)
            resize(items.length/2);
        if (head == tail) throw new NoSuchElementException();
        else if (head == items.length) head = 0;
        Item ret = items[head];
        items[head] = null;
        head++;
        return ret;
    }

    public boolean isEmpty() { return head == tail; }
    public int size() { return (tail < head) ? items.length + tail - head : tail - head; }
    public int capacity() { return items.length; }
    public Iterator<Item> iterator() { return new MyIterator();}
    private class MyIterator implements Iterator<Item> {
        private int index = head;
        @Override
        public boolean hasNext() { return index != tail; }
        @Override
        public Item next()
        {
            if (index == tail)
                throw new NoSuchElementException();
            if (index == items.length)
                index = 0;
            return items[index++];
        }
        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }
    public static void main(String[] args)
    {
        ResizingArrayQueueMy<Integer> test = new ResizingArrayQueueMy<Integer>();
        if (test.isEmpty())
            for (int i = 0; i < 10; i++)
            {
                test.enqueue(i);
            }
        int size = test.size();
        for (int i = 0; i < size; i++)
        {
            test.dequeue();
        }

        for (int i = 0; i < 12 ; i++)
        {
            test.enqueue(i);
            test.enqueue(i);
            test.dequeue();
        }
    }
}
