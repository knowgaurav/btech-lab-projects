class thread1 extends Thread{
    public void run(){
        int i = 0;
        while(i < 10) {
            System.out.println("Good Morning. - " + getPriority());
            i++;
        }
    }
}

class thread2 extends Thread{
    public void run(){
        int i = 0;
        while(i < 10) {
            System.out.println("Welcome!");
            i++;
            try {
                sleep(200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class exc_thread {
    public static void main(String[] args) {

        System.out.println(Thread.currentThread().getState());

        thread1 t1 = new thread1();
        thread2 t2 = new thread2();
        t1.setPriority(Thread.MAX_PRIORITY);
        t2.setPriority(Thread.MIN_PRIORITY);
        System.out.println("Current States: " + t1.getState() + " " + t2.getState());

        t1.start();
        t2.start();

        System.out.println("Current States: " + t1.getState() + " " + t2.getState());
    }
}
