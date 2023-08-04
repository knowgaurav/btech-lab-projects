import java.util.Set;

// class calc {
//     int a, b, c;

//     public int add(int a, int b) {
//         this.a = a;
//         this.b = b;
//         return this.a + this.b;
//     }

//     public int add(int a, int b, int c) {
//         this.a = a;
//         this.b = b;
//         this.c = c;
//         return this.a + this.b + this.c;
//     }
// }

// interface calc {
//     int add(int a, int b);
// }

class Bank {
    int balance, accID;
    String name;

    static int accNo = 0;

    Bank(int b, String n) {
        accNo++;
        balance = b;
        name = n;
        accID = accNo;
    }

    Bank(Bank b, int b1) {
        accNo++;
        this.balance = b1;
        this.name = b.name;
        this.accID = accNo;
    }

    Bank newAccount(int b) {
        Bank temp = new Bank(b, this.name);
        return temp;
    }

    void display() {
        System.out.println("Account ID: " + this.accID);
        System.out.println("Account Holder Name: " + this.name);
        System.out.println("Balance: " + this.balance);
        System.out.println("");
    }
}

public class lab {
    public static void main(String[] args) {
        // calc c1 = new calc();
        // System.out.println("Example of method overloading:\n");
        // System.out.println("Addition by passing two parameters: " + c1.add(10, 20));
        // System.out.println("Addition by passing three parameters: " + c1.add(10, 20,
        // 30));
        // calc c1 = new calc() {
        // @Override
        // public int add(int a, int b) {
        // return a + b;
        // }
        // };

        // System.out.println("Overriden Function output: " + c1.add(10, 20));

        System.out.println("Example of passing and returning of Object to/from methods:\n");

        Bank b1 = new Bank(1000, "Gaurav");
        b1.display();

        Bank b2 = new Bank(b1, 2000);
        b2.display();

        Bank b3 = b1.newAccount(3000);
        b3.display();
    }
}
