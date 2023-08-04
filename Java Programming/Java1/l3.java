public class lab3 {
    public static void main(String[] args) {
        int arr[] = new int[20];
        int sum = 0;
        float count = 0;
        for (int i = 0; i < args.length; i++) {
            arr[i] = Integer.valueOf(args[i]);
            sum += arr[i];
            count++;
        }
        float avg = sum / count;

        System.out.println("Sum is: " + sum);
        System.out.println("Average is: " + avg);
    }
}