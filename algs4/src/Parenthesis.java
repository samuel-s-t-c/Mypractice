import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Parenthesis {

    public static void main(String[] args) {
        char next;
        Stack<Character> stack = new Stack<>();
        while (!StdIn.isEmpty()) {
            next = StdIn.readChar();
            if ( parseChar(next, stack) == -1) {
                StdOut.println("false");
                return;
            }
        }
        StdOut.println("true");
    }
    private static int parseChar(char c, Stack<Character> stack) {
        switch (c) {
            case '[':
            case '{':
            case '(':
                stack.push(c);
                return 0;
            case ']':
              return check('[', stack.pop());
            case '}':
                return check('{', stack.pop());
            case ')':
                return check('(', stack.pop());
            default:
                return 0;
        }
    }
    private static int check(char c1, char c2) {
        StdOut.println(c2+" "+c1);
        if (c1 == c2)
            return 0;
        else
            return -1;
    }
}

