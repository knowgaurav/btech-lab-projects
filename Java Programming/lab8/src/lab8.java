abstract class movie1{
    public abstract void details();
}

class godfather extends movie1{
    final String name = "The Godfather";
    final int releaseYear = 1972;
    double rating = 9.2;
    @Override
    public void details() {
        System.out.println("Name: "+name);
        System.out.println("Release Year: "+releaseYear);
        System.out.println("Rating: "+rating+"/10");
    }
}

public class lab8 {
    public static void main(String []args){
        godfather g1 = new godfather();
        System.out.println("Program to demonstrate final & abstract keyword: ");
        g1.details();
    }
}
