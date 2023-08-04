import java.io.*;
import java.util.*;

class MyStack {
    private int arr[];
    private int top;
    private int capacity;

    MyStack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    public void push(int x) {
        if (isFull()) {
            System.out.println("Stack OverFlow");

            System.exit(1);
        }

        System.out.println("Inserting " + x);
        arr[++top] = x;
    }

    public int pop() {
        if (isEmpty()) {
            System.out.println("STACK EMPTY");
            System.exit(1);
        }
        return arr[top--];
    }

    public int getSize() {
        return top + 1;
    }

    public Boolean isEmpty() {
        return top == -1;
    }

    public Boolean isFull() {
        return top == capacity - 1;
    }

    public void printStack() {
        for (int i = 0; i <= top; i++) {
            System.out.print(arr[i] + ", ");
        }
    }

    // class test {
    // int x = 10;

    // private test() {
    // }

    // public static void print() {
    // test t = new test();
    // System.out.println(t.x);
    // }
    // }
}

class stackOps {

    MyStack stack1 = new MyStack(10);

    public synchronized void ops() {
        // System.out.println("Pushing: ");
        stack1.push(4);
        stack1.push(5);
        stack1.push(6);

        // System.out.println("Popping: ");
        System.out.println("Popped " + stack1.pop());
        System.out.println("Popped " + stack1.pop());
        System.out.println("Popped " + stack1.pop());
    }
}

// class stackOps {

// Stack stack1 = new Stack();

// public void s() {
// stack1.push(4);
// stack1.push(5);
// stack1.push(6);

// System.out.println(stack1.pop());
// System.out.println(stack1.pop());
// System.out.println(stack1.pop());
// }
// }

// class MyThread extends Thread {

// stackOps s1;

// MyThread(stackOps s1) {
// this.s1 = s1;
// }

// public void run() {
// s1.s();
// }
// }

// public class practice {
// public static void main(String[] args) {

// stackOps s = new stackOps();

// MyThread m1 = new MyThread(s);
// MyThread m2 = new MyThread(s);

// m1.start();
// m2.start();
// }
// }

// Stack implementation in Java

class MyThread extends Thread {

    stackOps s1 = new stackOps();

    MyThread(stackOps s1) {
        this.s1 = s1;
    }

    public void run() {
        s1.ops();
    }

}

public class practice {
    public static void main(String[] args) {
        // test t1 = new test();
        // System.out.println("Inside Class");
        // test.print();

        stackOps s = new stackOps();

        MyThread m1 = new MyThread(s);
        MyThread m2 = new MyThread(s);

        m1.start();
        m2.start();
    }
}