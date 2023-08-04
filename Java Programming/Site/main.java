import movie.movie;
import movie.inner.godfather;
import movie.inner.goodfellas;

public class main {
    public static void main(String[] args) {
        System.out.println("Packages Demo: ");
        movie m1 = new godfather();
        m1.details();
        System.out.print("\n");
        m1 = new goodfellas();
        m1.details();
    }
}
