import java.util.*;

class Student {
    int rollnum, marks1, marks2, marks3;
    String name;

    public void setData(int _rn, String _name, int _m1, int _m2, int _m3) {
        this.rollnum = _rn;
        this.name = _name;
        this.marks1 = _m1;
        this.marks2 = _m2;
        this.marks3 = _m3;
    }

    public void display() {
        System.out.print("\nStudent Details: ");
        System.out.print("\nName: " + name);
        System.out.print("\nRoll Number: " + rollnum);
        System.out.print("\nMarks 1: " + marks1);
        System.out.print("\nMarks 2: " + marks2);
        System.out.print("\nMarks 3: " + marks3);
        System.out.print("\n");
    }

    public void getdata(String info) {
        if (info.equals("Name")) {
            System.out.println("\n Name is: " + name);
        }
        if (info.equals("Roll Num")) {
            System.out.println("\n Roll Number is: " + rollnum);
        }
        if (info.equals("Marks 1")) {
            System.out.println("\n Marks in subject 1 is: " + marks1);
        }
        if (info.equals("Marks 2")) {
            System.out.println("\n Marks in subject 2 is: " + marks2);
        }
        if (info.equals("Marks 3")) {
            System.out.println("\n Marks in subject 3 is: " + marks3);
        }
    }
}

public class lab3 {

    static void menu() {
        System.out.println("School Portal: ");
        System.out.println(" Enter 1. Register New Student");
        System.out.println(" Enter 2. Display Student Info");
        System.out.println(" Enter 3. Get Student Details");
        System.out.println(" Enter 5. Exit Application");
    }

    public static void main(String[] args) {
        // int num1 = 0, num2 = 0, num3 = 0;
        // Scanner sc = new Scanner(System.in);
        // System.out.print("Enter first number: ");
        // num1 = sc.nextInt();
        // System.out.print("Enter second number: ");
        // num2 = sc.nextInt();
        // System.out.print("Enter third number: ");
        // num3 = sc.nextInt();
        // System.out.println("Largest of three numbers is: ");
        // if (num1 > num2 && num1 > num3) {
        // System.out.println("Num 1: " + num1);
        // } else if (num2 > num1 && num2 > num3) {
        // System.out.println("Num 2: " + num2);
        // } else {
        // System.out.println("Num 3: " + num3);
        // }

        // int num = Integer.valueOf(args[0]);

        // int fact = 1;
        // for (int i = 1; i < num; i++)
        // fact *= i;

        // System.out.println("Factorial of " + num + " is: " + fact);

        // int arr[] = new int[20];
        // int sum = 0;
        // float count = 0;
        // for (int i = 0; i < args.length; i++) {
        // arr[i] = Integer.valueOf(args[i]);
        // sum += arr[i];
        // count++;
        // }
        // float avg = sum / count;

        // System.out.println("Sum is: " + sum);
        // System.out.println("Average is: " + avg);

        menu();
        Student s1 = new Student();
        String name;
        int rollnum, m1, m2, m3;
        Scanner ch = new Scanner(System.in);

        while (true) {
            System.out.print("\nEnter Choice: ");
            int choice = ch.nextInt();

            Scanner sc = new Scanner(System.in);
            switch (choice) {
                case 1:
                    System.out.println("Registering New Student: ");
                    System.out.print("Enter Student Name: ");
                    name = sc.nextLine();
                    System.out.print("Enter Student Roll Number: ");
                    rollnum = sc.nextInt();
                    System.out.print("Enter Marks in Subject 1, 2, 3: ");
                    m1 = sc.nextInt();
                    m2 = sc.nextInt();
                    m3 = sc.nextInt();
                    s1.setData(rollnum, name, m1, m2, m3);
                    break;
                case 2:
                    s1.display();
                    break;
                case 3:
                    System.out.print("Enter the field you wish to see of the Student: ");
                    String field;
                    field = sc.nextLine();
                    s1.getdata(field);
                    break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println("Incorrect Command");
            }
        }
    }
}
