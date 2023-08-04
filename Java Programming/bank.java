public class Bank {
    final int MIN_BALANCE = 500;
    String name;
    String accountType;
    int balance;

    public Bank(String name, String accountType, int balance) {
        this.name = name;
        this.accountType = accountType;
        this.balance = balance;
    }

    public void deposit(int amount){
        balance+=amount;
        System.out.println("The amount " + amount +" has been deposited");
    }

    public void withdraw(int amount){
        if(balance-amount>=MIN_BALANCE){
            balance-=amount;
            System.out.println("The amount " + amount +" has been withdrawn");
        }
        else{
            System.out.println("Insufficient Balance as min balance maintained has to be " + MIN_BALANCE);
        }
    }

    public void display(){
        System.out.println("Bank account details: ");
        System.out.println("Name : " + name);
        System.out.println("Balance: " + balance);
    }
}

import java.util.Scanner;

public class shivam {
    public static void main(String[] args) {
        String name, accountType;
        int initBalance;

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the depositors name: ");
        name = scanner.nextLine();
        System.out.print("Enter the Account Type: ");
        accountType = scanner.next();
        System.out.print("Enter the Initial balance: ");
        initBalance = scanner.nextInt();

        Bank bank = new Bank(name, accountType, initBalance);

        int choice;
        displayMenu();
        do {
            System.out.print("\nEnter your choice: ");
            choice = scanner.nextInt();

            if (choice == 1)
                bank.display();

            else if (choice == 2) {
                System.out.print("Enter the amount to be deposited: ");
                int amount = scanner.nextInt();
                bank.deposit(amount);
            }

            else if (choice == 3) {
                System.out.print("Enter the amount to be withdrawn: ");
                int amount = scanner.nextInt();
                bank.withdraw(amount);
            }

            else if (choice == 4)
                displayMenu();

            else if (choice == 5)
                break;

            else
                System.out.println("Wrong choice!!!!");

        } while (choice != 5);

    }

    public static void displayMenu() {
        System.out.println("Menu");
        System.out.println("1 to display account details");
        System.out.println("2 to deposit an amount");
        System.out.println("3 to deposit an amount");
        System.out.println("4 to display menu");
        System.out.println("5 to exit");
    }
}