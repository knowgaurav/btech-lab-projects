import java.util.Set;

// class Animal {
// int legs;

// Animal(int legs) {
// this.legs = legs;
// }
// }

// class Dog extends Animal {
// String name;

// Dog(String name) {
// super(4);
// this.name = name;
// }

// void display() {
// System.out.println("My name is " + name + " and I have " + legs + " legs\n");
// }
// }

// class Babydog extends Dog {
// Babydog(String name) {
// super(name);
// }

// int age = 2;

// void display() {
// System.out.println("My name is " + name + " and I have " + legs + " legs and
// I am " + age + " years old.\n");
// }
// }

// class Shape {
// int l, b, h;

// Shape() {
// l = b = h = 0;
// }

// Shape(int l, int b, int h) {
// this.l = l;
// this.b = b;
// this.h = h;
// }

// int volume() {
// return l * b * h;
// }

// }

// class Game {
// static int playercount;

// static {
// playercount = 0;
// }

// String playerName;
// int playerScore;
// int playerID;

// Game(String playerName, int playerScore) {
// playercount++;
// this.playerName = playerName;
// this.playerScore = playerScore;
// playerID = playercount;
// }

// void display() {
// System.out.println("Player ID: " + playerID);
// System.out.println("Player Name: " + playerName);
// System.out.println("Player Score: " + playerScore);
// }

// }

class A {
    public int a = 10;

    public void get() {
        System.out.println("A= " + a);
    }
}

class B extends A {
    int b = 100;

    public void get() {
        System.out.println("B= " + b);
    }

    public void get2() {
        System.out.println("B2= " + b * 2);
    }
}

public class lab {
    public static void main(String[] args) {
        A obj = new B();
        obj.get();
        obj.get2();

        B obj2 = new A();

    }
}

// public class lab {
// public static void main(String args[]) {

// System.out.println("Example of Static Keyword: ");
// System.out.println("");

// Game g1 = new Game("Gaurav", 100);
// Game g2 = new Game("Naman", 50);

// System.out.println("Details of Player 1: ");
// g1.display();
// System.out.println("");
// System.out.println("Details of Player 2: ");
// g2.display();

// System.out.println("\nTotal players = " + Game.playercount);

// // System.out.println("Example of Constructor Overloading: ");
// // Shape S1 = new Shape();
// // System.out.println("Volume by passing no variable in constructor: " +
// // S1.volume());

// // Shape S2 = new Shape(10, 20, 30);
// // System.out.println("\nVolume by passing values 10, 20, 30 in constructor:
// " +
// // S2.volume());
// // System.out.println("Example of Single Inheritance: ");
// // Dog d1 = new Dog("Scooby Doo");
// // d1.display();

// // System.out.println("\nExample of Multilevel Inheritance: ");
// // Babydog b1 = new Babydog("Baby Scooby Doo");
// // b1.display();
// }
// }
