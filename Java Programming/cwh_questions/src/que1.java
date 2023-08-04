public class que1 {
    public static void main(String[] args) {
        int []arr = new int[5];
        int sum=0;
        double avg;

        for(int i=0; i<5; i++) {
            arr[i] = Integer.parseInt(args[i]);
            sum+=arr[i];
        }

        avg = sum/5.0;

        System.out.println("Sum is: " + sum);
        System.out.println("Average is: " + avg);
    }
}
