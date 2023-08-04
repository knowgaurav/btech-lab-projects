public class lab10 {
    public static class Table {
        void printTable(int n) {
            synchronized (this) {
                System.out.println("Table of " + n);
                for (int i = 1; i <= 10; i++) {
                    System.out.println(n * i);
                }
            }
        }
    }

    public static class MyThread extends Thread {
        Table t;
        int n;

        MyThread(Table t, int n) {
            this.t = t;
            this.n = n;
        }

        public void run() {
            t.printTable(n);
        }
    }

    public static void main(String[] args) {
        Table t1 = new Table();

        MyThread m1 = new MyThread(t1, 5);
        MyThread m2 = new MyThread(t1, 100);

        m1.start();
        m2.start();
    }
}
