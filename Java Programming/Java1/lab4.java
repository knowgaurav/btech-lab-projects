import java.util.*;

// public class lab4 {

// public static void display(int arr[]) {
// System.out.println("The array is: ");
// System.out.print("[ ");
// for (int i = 0; i < arr.length; i++) {
// System.out.print(arr[i] + ", ");
// }
// System.out.print("]");
// System.out.println("");
// }

// public static void main(String[] args) {
// char arr0[]; // Declaring
// System.out.println("Array Initilization while declaring: ");
// int arr1[] = { 1, 2, 3, 4, 5 }; // Initialising
// display(arr1);
// System.out.println("");

// Scanner sc = new Scanner(System.in);
// System.out.println("Enter the size of the array: ");
// int n = sc.nextInt();
// int arr2[] = new int[n];
// System.out.println("Enter the elements of the array: ");
// for (int i = 0; i < arr2.length; i++) {
// arr2[i] = sc.nextInt();
// }

// display(arr2);
// }
// }

// public class lab4 {
// public static int sum(int[] arr) {
// int sum = 0;
// for (int i = 0; i < arr.length; i++) {
// sum += arr[i];
// }
// return sum;
// }

// public static int[] createArr() {
// Scanner sc = new Scanner(System.in);
// System.out.println("Enter the size of the array: ");
// int n = sc.nextInt();
// int[] arr = new int[n];
// System.out.println("Enter the elements of the array: ");
// for (int i = 0; i < arr.length; i++) {
// arr[i] = sc.nextInt();
// }
// return arr;
// }

// public static void display(int arr[]) {
// System.out.println("The array is: ");
// System.out.print("[ ");
// for (int i = 0; i < arr.length; i++) {
// System.out.print(arr[i] + ", ");
// }
// System.out.print("]");
// System.out.println("");
// }

// public static void main(String[] args) {
// int[] arr = createArr();
// System.out.println("");
// display(arr);
// int sum = sum(arr);
// System.out.println("");
// System.out.println("Sum of the array = " + sum);
// }
// }
// public class lab4 {
// public static void main(String[] args) {
// Scanner sc = new Scanner(System.in);

// System.out.println("Enter the rows of jagged array: ");
// int n = sc.nextInt();

// int arr[][] = new int[n][];

// System.out.println();
// for (int i = 0; i < n; i++) {
// System.out.print("Enter no. of columns for row " + (i + 1) + " of jagged
// array: ");
// int m = sc.nextInt();
// arr[i] = new int[m];
// }

// System.out.println();
// for (int i = 0; i < arr.length; i++) {
// int row = i + 1;
// System.out.print("Enter the elements of row " + row + ": ");
// for (int j = 0; j < arr[i].length; j++) {
// arr[i][j] = sc.nextInt();
// }
// }

// System.out.println();
// System.out.println("The jagged array is: ");
// for (int i = 0; i < arr.length; i++) {
// for (int j = 0; j < arr[i].length; j++) {
// System.out.print(arr[i][j] + " ");
// }
// System.out.println();
// }
// }
// }

public class lab4 {
    public static void main(String[] args) {
        String s1 = "Gaurav";
        String s2 = new String("Singh");
        System.out.println("Performing various String Functions: \n");
        System.out.println("-> Concat: ");
        System.out.println(s1 + " " + s2);
        System.out.println(s1.concat(" ").concat(s2));
        System.out.println("-> Compare: ");
        System.out.println(s1.compareTo(s2));
        System.out.println(s1.compareTo("Gaurav"));
        System.out.println("-> Substring: ");
        System.out.println(s1.substring(0, 4));
        System.out.println(s2.substring(1));
        System.out.println("-> CharAt: ");
        System.out.println(s1.charAt(0));
        System.out.println(s2.charAt(0));
    }
}