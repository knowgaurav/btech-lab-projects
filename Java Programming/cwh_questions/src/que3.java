class Box{
    int w, h, l;

    Box(){
        w = h = l = 0;
    }

    Box(int w, int h, int l){
        this.w = w;
        this.h = h;
        this.l = l;
    }

    //For Cube
    Box(int s){
        w = h = l = s;
    }

    int area(){
        return w * l;
    }

    int volume(){
        return w * l * h;
    }
}

public class que3 {
    public static void main(String[] args) {
        Box b1 = new Box();
        Box b2 = new Box(10, 20, 30);
        Box b3 = new Box(10);

        System.out.println("For Box 1, Area = " + b1.area() + ", Volume = " + b1.volume());
        System.out.println("For Box 2, Area = " + b2.area() + ", Volume = " + b2.volume());
        System.out.println("For Box 3, Area = " + b3.area() + ", Volume = " + b3.volume());
    }
}
