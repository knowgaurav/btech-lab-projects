import java.util.*;

class emp_details {
    int id, sal;
    String name, desg;

    emp_details(int _id, String _name, int _sal, String _desg) {
        this.id = _id;
        this.name = _name;
        this.sal = _sal;
        this.desg = _desg;
    }

    public void getdata() {
        System.out.print("\n Name: " + name);
        System.out.print("\n ID: " + id);
        System.out.print("\n Designation: " + desg);
        System.out.print("\n Salary: " + sal);
        System.out.println();
    }

    void incSalary() {
        if (desg.compareTo("Manager") == 0) {
            sal += 5000;
        }
        if (desg.compareTo("General Manager") == 0) {
            sal += 10000;
        }
        if (desg.compareTo("CEO") == 0) {
            sal += 20000;
        }
        if (desg.compareTo("Worker") == 0) {
            sal += 2000;
        }
    }
}

public class employee {

    public static void main(String[] args) {
        System.out.println("Enter the employee info: ");
        Scanner sc = new Scanner(System.in);

        String ename, edesg;
        int eid, esal;
        System.out.print("Enter Employee Name: ");
        ename = sc.nextLine();
        System.out.print("Enter Employee ID: ");
        eid = sc.nextInt();
        System.out.print("Enter Employee Designation: ");
        edesg = sc.next();
        System.out.print("Enter Employee Salary: ");
        esal = sc.nextInt();

        emp_details e1 = new emp_details(eid, ename, esal, edesg);
        System.out.println("\nBefore Increment: ");
        e1.getdata();
        System.out.println("\nAfter Increment: ");
        e1.incSalary();
        e1.getdata();
    }
}