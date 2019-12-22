
import java.util.Iterator;
import java.util.NoSuchElementException;

public class ResizingArrayStack<Item> implements Iterable<Item>
{
    private Item[] items = (Item[]) new Object[1];
    private int N = 0;

    private void resize(int size)
    {
        Item[] temp = (Item[]) new Object[size];
        for (int i = 0; i < N; i++)
            temp[i] = items[i];
        items = temp;
    }

    public void push(Item item)
    {
        if (N == items.length)
            resize(2*N);
        items[N++] = item;
    }

    public Item pop()
    {
        Item item = items[--N];
        items[N] = null;
        if (N > 0 && N == items.length/4)
            resize(items.length/2);
        return item;
    }

    public int size() { return N; }

    public int capacity() { return items.length; }

    public Iterator<Item> iterator() { return new ReverseArrayIterator(); }

    private class ReverseArrayIterator implements Iterator<Item>
    {
        private int i = N;
        public boolean hasNext() { return i > 0; }
        public Item next()
        {
            if (i == 0) throw new NoSuchElementException();
            return items[--i];
        }
        public void remove() { throw new UnsupportedOperationException(); }
    }

    public static void main(String[] args)
    {
        ResizingArrayStack<String> a = new ResizingArrayStack<String>();
        System.out.println("size:"+a.size()+" capacity:"+a.capacity());
        for (int i = 0; i < 10; i++)
        {
            a.push(String.valueOf(i));
            System.out.println("size:"+a.size()+" capacity:"+a.capacity());
        }
    }
}
