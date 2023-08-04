import java.util.*;

class employee {
    int id, sal;
    String name, desg;

    employee(int _id, String _name, int _sal, String _desg) {
        this.id = _id;
        this.name = _name;
        this.sal = _sal;
        this.desg = _desg;
    }

    /*
     * public void setData(String n, int i) { this.name = n; this.id = i; }
     */

    public void getdata() {
        System.out.print("\n Name: " + name);
        System.out.print("\n ID: " + id);
        System.out.print("\n Designation: " + desg);
        System.out.print("\n Salary: " + sal);
    }

    /*
     * void setData(String ename, int eid, String edesg, int esal) { name = ename;
     * id = eid; desg = edesg; sal = esal; }
     * 
     * 
     * void getdata() { System.out.println("\n Name: " + name);
     * System.out.println(" Id: " + id); System.out.println(" Desgignation: " +
     * desg); System.out.println(" Salary: " + sal); }
     * 
     * 
     * void incSalary() { if (desg.compareTo("Manager") == 0) { sal += 5000;
     * System.out.println("\n Incremented Salary :" + sal); } if
     * (desg.compareTo("General Manager") == 0) { sal += 10000;
     * System.out.println("\n Incremented Salary :" + sal); } if
     * (desg.compareTo("CEO") == 0) { sal += 20000;
     * System.out.println("\n Incremented Salary :" + sal); } if
     * (desg.compareTo("Worker") == 0) { sal += 2000;
     * System.out.println("\n Incremented Salary :" + sal); } }
     */
}

class programmer extends employee {
    programmer(int _id, String _name) {
        super(_id, _name, 100000, "Programmer");
    }
}

/*
 * class analyst extends employee { desg = "Analyst"; sal = 50000; }
 * 
 * class projectLeader extends employee { desg = "Project Leader"; sal = 150000;
 * }
 */
/*
 * class Bank { String holderName, accType; static int accCount = 100; int
 * accNum; double balance;
 * 
 * void newAcc(String name, String type, double deposite) { holderName = name;
 * accType = type; balance = deposite; accNum = accCount; accCount++;
 * System.out.
 * println(" Congratulations, account opened successfully. Account Number => " +
 * accNum); }
 * 
 * void accDetails() { System.out.println(" Details: \n Holder Name:" +
 * holderName + ", Balance: " + balance); }
 * 
 * void deposit(double amt) { balance = balance + amt;
 * System.out.println(" Deposite Successful! Updated Balance: " + balance); }
 * 
 * void withdrawal(double amt) { if (balance >= amt && balance > 500) { balance
 * = balance - amt; System.out.println(" Updated Balance: " + balance); } else {
 * System.out.
 * println(" Insufficient Balance (Min Balance should be Rs. 500/-). Transaction Failed!!"
 * ); } } }
 */

public class lab2 {

    // static void menu() {
    // System.out.println("Banking Application: ");
    // System.out.println(" Enter 1. Open New Account");
    // System.out.println(" Enter 2. See Account Details");
    // System.out.println(" Enter 3. Deposit Amount");
    // System.out.println(" Enter 4. Withdraw Amount");
    // System.out.println(" Enter 5. Exit Application");
    // }

    public static void main(String[] args) {

        programmer p = new programmer(1001, "Mike Tyson");
        System.out.println("Details of object of Programmer Class: ");
        p.getdata();
        /*
         * System.out.println("\n"); analyst a = new analyst();
         * a.setData("Brock Lesnar", 1002);
         * System.out.println("Details of object of Analyst Class: "); a.getdata();
         * System.out.println("\n"); projectLeader pl = new projectLeader();
         * pl.setData("The Rock", 1003);
         * System.out.println("Details of object of Project Leader Class: ");
         * pl.getdata();
         */
        /*
         * Bank b1 = new Bank(); String name, type; double amt; Scanner ch = new
         * Scanner(System.in);
         * 
         * menu();
         * 
         * while (true) {
         * 
         * System.out.println(" Opening New Account, Enter Name, Type and Deposit: ");
         * name = sc.nextLine(); type = sc.next(); amt = sc.nextDouble();
         * b1.newAcc(name, type, amt);
         * 
         * System.out.println("\n"); b1.accDetails(); System.out.println("\n");
         * System.out.println(" Enter the amount to be deposited: "); amt =
         * sc.nextDouble(); b1.deposit(amt); System.out.println("\n");
         * System.out.println(" Enter the amount to be Withdrawn: "); amt =
         * sc.nextDouble(); b1.withdrawal(amt);
         * 
         * System.out.print("\n Enter Choice: "); int choice = ch.nextInt();
         * 
         * Scanner sc = new Scanner(System.in); switch (choice) { case 1:
         * System.out.println(" Opening New Account, Enter Name, Type and Deposit: ");
         * name = sc.nextLine(); type = sc.next(); amt = sc.nextDouble();
         * b1.newAcc(name, type, amt); break; case 2: b1.accDetails(); break; case 3:
         * System.out.print(" Enter the amount to be deposited: "); amt =
         * sc.nextDouble(); b1.deposit(amt); break; case 4:
         * System.out.print(" Enter the amount to be Withdrawn: "); amt =
         * sc.nextDouble(); b1.withdrawal(amt); break; case 5: System.exit(0); default:
         * System.out.println("Incorrect Command"); } }
         */
        /*
         * System.out.println("Enter the employee info: "); Scanner sc = new
         * Scanner(System.in);
         * 
         * String ename, edesg; int eid, esal; ename = sc.nextLine(); eid =
         * sc.nextInt(); edesg = sc.next(); esal = sc.nextInt(); e1.setData(ename, eid,
         * edesg, esal); System.out.println("Before Increment: "); e1.getdata();
         * System.out.println("After Increment: "); e1.incSalary(); e1.getdata();
         * e1.setData("Gaurav", 100, "Manager", 10000); e1.getdata(); e1.incSalary();
         * e1.getdata();
         */
    }
}