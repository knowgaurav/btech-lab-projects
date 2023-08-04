import java.util.Scanner;

class fuel_monitor{
    double ini_tank_size;
    double ini_effi;
    double fuel_in_tank;

    fuel_monitor(double tankCapacity, double efficiency){
        ini_tank_size = tankCapacity;
        ini_effi = efficiency;
        fuel_in_tank = 0;
    }

    void refuel(double fuel){
        fuel_in_tank += fuel;
    }

    double[] details(){
        double []det = new double[3];
        det[0] = this.ini_tank_size;
        det[1] = this.ini_effi;
        det[2] = this.fuel_in_tank;
        return det;
    }

    double add_fuel(){
        return ini_tank_size - fuel_in_tank;
    }

    double drive_distance(){
        return fuel_in_tank * ini_effi;
    }
}

public class que4 {

    private static void menu(){
        System.out.println("\n--- Menu ---");
        System.out.println("1. Add Fuel");
        System.out.println("2. Drive");
        System.out.println("3. Exit");
    }

    public static void main(String[] args) {
        int choice;
        Scanner sc = new Scanner(System.in);
        fuel_monitor f1;

        System.out.print("Enter Tank Size (l): ");
        double tc = sc.nextDouble();
        System.out.print("Enter initial efficiency (km/l): ");
        double e = sc.nextDouble();
        f1 = new fuel_monitor(tc, e);

        menu();

        while(true){
            System.out.print("\nEnter Choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    double f;
                    System.out.print("Enter fuel (l): ");
                    f = sc.nextDouble();
                    if(f <= f1.add_fuel())
                        f1.refuel(f);
                    else
                        System.out.println("Insufficient Capacity!");
                    break;
                case 2:
                    double []f_det = f1.details();
                    System.out.println("Fuel Details: ");
                    System.out.println("Fuel Capacity: " + f_det[0] + "l");
                    System.out.println("Efficiency: " + f_det[1] + "km/l");
                    System.out.println("Fuel in Tank: " + f_det[2] + "l");
                    System.out.println("Range: " + f1.drive_distance() + "km");
                    break;
                case 3:
                    System.exit(0);
                default:
                    System.out.println("Invalid Input!");
            }
        }
    }
}
