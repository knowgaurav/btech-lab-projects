import java.util.Scanner;

public class bankers {
    private int need[][], allocate[][], max[][], avail[][], np, nr;

    private void input() {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter no. of processes: ");
        np = sc.nextInt();
        System.out.print("Enter no. of resources: ");
        nr = sc.nextInt();
        need = new int[np][nr];
        max = new int[np][nr];
        allocate = new int[np][nr];
        avail = new int[1][nr];

        System.out.println("\nEnter resource allocation matrix: ");
        for (int i = 0; i < np; i++)
            for (int j = 0; j < nr; j++)
                allocate[i][j] = sc.nextInt();

        System.out.println("\nEnter max requirement matrix: ");
        for (int i = 0; i < np; i++)
            for (int j = 0; j < nr; j++)
                max[i][j] = sc.nextInt();

        System.out.println("\nEnter available matrix: ");
        for (int j = 0; j < nr; j++)
            avail[0][j] = sc.nextInt();

        sc.close();
    }

    private int[][] calc_need() {
        for (int i = 0; i < np; i++)
            for (int j = 0; j < nr; j++)
                need[i][j] = max[i][j] - allocate[i][j];

        return need;
    }

    private boolean check(int i) {
        for (int j = 0; j < nr; j++)
            if (avail[0][j] < need[i][j])
                return false;

        return true;
    }

    public void isSafe() {
        input();
        calc_need();

        System.out.println("\nNeed matrix: ");
        for (int i = 0; i < np; i++) {
            for (int j = 0; j < nr; j++)
                System.out.print(need[i][j] + " ");

            System.out.println("");
        }
        System.out.println("");

        boolean done[] = new boolean[np];
        int p = 0;

        while (p < np) {
            boolean allocated = false;
            for (int i = 0; i < np; i++)
                if (!done[i] && check(i)) {
                    for (int j = 0; j < nr; j++)
                        avail[0][j] = avail[0][j] - need[i][j] + max[i][j];
                    System.out.println("Process Executed: " + (i + 1));
                    allocated = done[i] = true;
                    p++;
                }
            if (!allocated)
                break;
        }
        if (p == np)
            System.out.println("\nResources are safely allocated!");
        else
            System.out.println("Resources can't be safely allocated!");
    }

    public static void main(String[] args) {
        bankers b1 = new bankers();
        b1.isSafe();
    }
}