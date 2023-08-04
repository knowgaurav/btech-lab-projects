import java.util.Scanner;

interface shapes{
    double perimeter();
}

class circle implements shapes{
    double r;
    Scanner sc = new Scanner(System.in);

    void setter(){
        System.out.println("Enter the radius: ");
        r = sc.nextInt();
    }

    @Override
    public double perimeter() {
        return 2*3.14*r;
    }
}

class rectangle implements shapes{
    int l, b;
    Scanner sc = new Scanner(System.in);

    void setter(){
        System.out.println("Enter the length: ");
        l = sc.nextInt();
        System.out.println("Enter the breadth: ");
        b = sc.nextInt();
    }

    @Override
    public double perimeter() {
        return 2*(l+b);
    }
}

public class que2 {
    public static void main(String[] args) {
        circle c1 = new circle();
        rectangle r1 = new rectangle();

        c1.setter();
        System.out.println("Perimeter of circle: "+ c1.perimeter());

        r1.setter();
        System.out.println("Perimeter of rectangle: "+ r1.perimeter());
    }
}
