class employee {
    int id, sal;
    String name, desg;

    employee(int _id, String _name, int _sal, String _desg) {
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
        System.out.println("\n");
    }

}

class programLeader1 {
    int id, sal;
    String name, desg;

    programLeader1(int _id, String _name) {
        this.id = _id;
        this.name = _name;
        this.sal = 120000;
        this.desg = "Program Leader";
    }

    public void getdata() {
        System.out.print("\n Name: " + name);
        System.out.print("\n ID: " + id);
        System.out.print("\n Designation: " + desg);
        System.out.print("\n Salary: " + sal);
        System.out.println("\n");
    }

}

class projectLeader extends employee {
    projectLeader(int _id, String _name) {
        super(_id, _name, 120000, "Project Leader");
    }
}

class programmer extends employee {
    programmer(int _id, String _name) {
        super(_id, _name, 100000, "Programmer");
    }
}

class analyst extends employee {
    analyst(int _id, String _name) {
        super(_id, _name, 80000, "Analyst");
    }
}

public class inheritance {
    public static void main(String[] args) {
        projectLeader pl = new projectLeader(1000, "Triple H");
        System.out.println("Details of object of Project Leader Class: ");
        pl.getdata();

        programmer p = new programmer(1001, "Mike Tyson");
        System.out.println("Details of object of Programmer Class: ");
        p.getdata();

        analyst a = new analyst(1002, "Brock Lesnar");
        System.out.println("Details of object of Analyst Class: ");
        a.getdata();

        programLeader1 pl1 = new programLeader1(1003, "The Undertaker");
        System.out.println("Details of object of Project Leader Class (No Inheritance): ");
        pl1.getdata();
    }
}
