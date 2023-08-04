import java.util.*;

class account {
    String holderName, accType;
    static int accCount = 100;
    int accNum;
    double balance;

    void newAcc(String name, String type, double deposite) {
        holderName = name;
        accType = type;
        balance = deposite;
        accNum = accCount;
        accCount++;
        System.out.println("Congratulations, account opened successfully. Account Number => " + accNum);
    }

    void accDetails() {
        System.out.println("Details: \nHolder Name:" + holderName + ", Balance: " + balance);
    }

    void deposit(double amt) {
        balance = balance + amt;
        System.out.println("Deposite Successful! Updated Balance: " + balance);
    }

    void withdrawal(double amt) {
        if (balance >= amt && balance > 500) {
            balance = balance - amt;
            System.out.println("Updated Balance: " + balance);
        } else {
            System.out.println("Insufficient Balance (Min Balance should be Rs. 500/-). Transaction Failed!!");
        }
    }
}

public class bank {

    static void menu() {
        System.out.println("Banking Application: ");
        System.out.println(" Enter 1. Open New Account");
        System.out.println(" Enter 2. See Account Details");
        System.out.println(" Enter 3. Deposit Amount");
        System.out.println(" Enter 4. Withdraw Amount");
        System.out.println(" Enter 5. Exit Application");
    }

    public static void main(String[] args) {

        account a1 = new account();
        String name, type;
        double amt;
        Scanner ch = new Scanner(System.in);

        // System.out.println("Opening New Account: ");
        // System.out.print("Enter Account Holder Name: ");
        // name = ch.nextLine();
        // System.out.print("Enter Account Type: ");
        // type = ch.next();
        // System.out.print("Enter Initial Deposit: ");
        // amt = ch.nextDouble();
        // a1.newAcc(name, type, amt);

        // System.out.println("\n");
        // a1.accDetails();
        // System.out.println("\n");
        // System.out.println(" Enter the amount to be deposited: ");
        // amt = ch.nextDouble();
        // a1.deposit(amt);
        // System.out.println("\n");
        // System.out.println(" Enter the amount to be Withdrawn: ");
        // amt = ch.nextDouble();
        // a1.withdrawal(amt);

        menu();

        while (true) {
            System.out.print("\nEnter Choice: ");
            int choice = ch.nextInt();

            Scanner sc = new Scanner(System.in);
            switch (choice) {
                case 1:
                    System.out.println("Opening New Account: ");
                    System.out.print("Enter Account Holder Name: ");
                    name = sc.nextLine();
                    System.out.print("Enter Account Type: ");
                    type = sc.next();
                    System.out.print("Enter Initial Deposit: ");
                    amt = sc.nextDouble();
                    a1.newAcc(name, type, amt);
                    break;
                case 2:
                    a1.accDetails();
                    break;
                case 3:
                    System.out.print("Enter the amount to be deposited: ");
                    amt = sc.nextDouble();
                    a1.deposit(amt);
                    break;
                case 4:
                    System.out.print("Enter the amount to be Withdrawn: ");
                    amt = sc.nextDouble();
                    a1.withdrawal(amt);
                    break;
                case 5:
                    System.exit(0);
                default:
                    System.out.println("Incorrect Command");
            }
        }

    }
}