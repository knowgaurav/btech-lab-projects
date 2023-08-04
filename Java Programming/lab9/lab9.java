import java.util.Scanner;

class NegativeInputException extends Exception {
    public String toString() {
        return "Input cannot be negative!";
    }
}

/**
 * <h1>Divides Two Array Variables!</h1>
 * <p>
 * The lab9 program implements an application that simply divides two given
 * integer numbers at the inputed array indexes and Prints the output on the
 * screen.
 * </p>
 *
 * @author Gaurav Singh
 * @version 1.0
 * @since 2020-02-23
 */

public class lab9 {

    /**
     * This is the lab9 constructor.
     */
    lab9() {
    }

    /**
     * This is the divide method which returns the divison of two integers of an
     * array.
     * 
     * @param arr This is the array
     * @param i   This is the first index
     * @param j   This is the second index
     * @return division of Arr[i] by Arr[j].
     */

    public static int divide(int arr[], int i, int j) {
        return arr[i] / arr[j];
    }

    /**
     * This is the main method which makes use of addNum method.
     * 
     * @param args Unused.
     * @return Nothing.
     * @exception ArithmeticException On Division by Zero.
     * @see ArithmeticException
     * @exception ArrayIndexOutOfBoundsException On invalid Array Index
     * @see ArrayIndexOutOfBoundsException
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter the size of the array: ");
        int size = sc.nextInt();

        int A[] = new int[size];

        System.out.print("\nEnter the elements of the array: ");

        try {

            for (int i = 0; i < A.length; i++) {
                int j = sc.nextInt();
                if (j < 0) {
                    throw new NegativeInputException();
                }
                A[i] = j;
            }

            System.out.print("\nEnter the indexes to divide: ");
            int i = sc.nextInt();
            int j = sc.nextInt();

            int divide = divide(A, i, j);
            System.out.println("Division result: " + divide);
        } catch (ArithmeticException e) {
            System.out.println("Division by zero not allowed, try again!");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Index is Invalid, try again!");
        } catch (NegativeInputException e) {
            System.out.println("Input cannot be negative, try again!");
        } finally {
            System.out.println("\nException Handled!\n");
        }

        System.out.println("Program is ending. Thanks for using!");
    }
}
