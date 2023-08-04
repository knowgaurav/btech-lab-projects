package parent;

public class movie{
    String name;
    int releaseYear;
    double rating;

    public movie(String name, int releaseYear, double rating){
        this.name = name;
        this.releaseYear = releaseYear;
        this.rating = rating;
    }
    public void details() {
        System.out.println("Name: "+name);
        System.out.println("Release Year: "+releaseYear);
        System.out.println("Rating: "+rating+"/10");
    }
}
