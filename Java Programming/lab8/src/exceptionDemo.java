import java.util.Scanner;

class NegativeInputException extends Exception {
    public String toString() {
        return "Input cannot be negative!";
    }
}

public class exceptionDemo {
    static void menu() {
        System.out.println("\nException Handling Demo: ");
        System.out.println(" Enter 1. To divide two array elements");
        System.out.println(" Enter 2. To display array elements");
        System.out.println(" Enter 3. Exit Application");
    }

    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter the size of the array: ");
        int size = sc.nextInt();

        int A[] = new int[size];
        System.out.print("\nEnter the elements of the array: ");
        try{
            for(int i=0; i<A.length; i++){
            int j = sc.nextInt();
            if (j < 0) {
                throw new NegativeInputException();
            }
                A[i] = j;
            }
        }   catch(NegativeInputException e){
            System.out.println("Input cannot be negative, try again!");
        }

        menu();

        while(true) {
            System.out.println("\nEnter a command(1-2 or 3 to quit): ");
            System.out.print("Enter Choice: ");
            int choice = sc.nextInt();

            switch(choice){
                case 1: try {
                    System.out.print("\nEnter the indexes to divide: ");
                    int i = sc.nextInt();
                    int j = sc.nextInt();
                    int divide = A[i] / A[j];
                    System.out.println("Division result: " + divide);
                } catch (ArithmeticException e) {
                    System.out.println("Division by zero not allowed, try again!");
                }
                catch (ArrayIndexOutOfBoundsException e){
                    System.out.println("Index is Invalid, try again!");
                }
                break;
                case 2:
                    System.out.print("Array is: ");
                    System.out.print("[ ");
                    for(int i=0; i<A.length; i++){
                        if(i!=A.length-1)
                            System.out.print(A[i]+", ");
                        else
                            System.out.print(A[i]);
                    }
                    System.out.print(" ]\n");
                    break;
                case 3:
                    System.out.println("Safely Exiting the Program. Thanks for using!");
                    System.exit(0);
            }
        }
    }
}
