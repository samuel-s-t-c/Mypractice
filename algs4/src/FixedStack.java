import java.awt.event.ItemEvent;
import java.util.Iterator;

public class FixedStack<Item> implements Iterable<Item>{
    private Item[] items;
    private int N;

    public FixedStack(int cap) {
        items = (Item[]) new Object[cap];
    }

    public Iterator<Item> iterator() {
        return new ReverseArrayIterator();
    }

    private class ReverseArrayIterator implements Iterator<Item> {

    }

    public void push(Item item){
        if (N == items.length)
            resize(2*N);
        items[N++] = item;
    }

    public Item pop() {
        Item item = items[--N];
        items[N] = null;
        if (N > 0 && N == items.length/4)
            resize(items.length/2);
        return item;
    }

    private void resize(int size) {
        Item[] temp = (Item[]) new Object[size];
        for (int i = 0; i < N; i++)
            temp[i] = items[i];
        items = temp;
    }
    public static void main(String[] args) {
    FixedStack<Integer> s = new FixedStack<Integer>(2);
    s.push(2);
    s.pop();
    }
}
