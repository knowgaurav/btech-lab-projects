import java.math.*;
import java.io.*;
import java.util.*;

public class scannerInput {
    public static void main(String[] args) throws IOException {
        /*
         * Scanner sc = new Scanner(System.in);
         * 
         * String s = sc.nextLine();
         * 
         * System.out.println("You Entered String " + s);
         * 
         * int x = sc.nextInt();
         * 
         * System.out.println("You Entered Integer " + x);
         * 
         * float f = sc.nextFloat();
         * 
         * System.out.println("You Entered Float " + f);
         */

        Scanner in = new Scanner(System.in);

        int x = in.nextInt();

        if (x % 2 == 0)
            System.out.println("Even");
        else
            System.out.println("Odd");

    }
}
