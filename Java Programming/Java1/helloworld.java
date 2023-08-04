/**
 * Hello World
 */
public class helloworld {
    public static void main(String[] args) {
        int x = 100;
        for (int i = 0; i < args.length; i++) {
            System.out.println(args[i]);
        }

        int[] arr = { 10, 20, 30, 40, 50 };

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }

        Integer z = new Integer(100);
        System.out.println(z.compareTo(99));
    }
}
