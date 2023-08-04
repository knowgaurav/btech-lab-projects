import java.util.Scanner;

class stringFormatter{
    public String[] reverse(String []str){
        String[] answer = new String[5];

        for(int i=0; i<5; i++){
            StringBuilder sb = new StringBuilder(str[i]);
            sb.reverse();
            String ans = sb.toString().trim();
            answer[i] = ans;
        }

        return answer;
    }

    public void sort(String []str){
        String temp;

        for(int i=0; i<str.length; i++){
            for(int j=i+1; j<str.length; j++){
                if(str[i].compareTo(str[j]) > 0){
                    temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
            }
        }
    }
}

public class que5 {
    public static void main(String[] args) {
        stringFormatter s1 = new stringFormatter();
        String []question = new String[5];

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter 5 words: ");

        for(int i=0; i<5; i++){
            question[i] = sc.nextLine();
        }

        String []ans = s1.reverse(question);
        s1.sort(ans);

        System.out.println("\nReversed & Sorted List: ");

        for(int i=0; i<5; i++){
            System.out.println(ans[i]);
        }
    }
}
