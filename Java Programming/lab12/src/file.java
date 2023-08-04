import java.io.*;
import java.lang.annotation.Inherited;
import java.lang.annotation.*;
import java.lang.reflect.*;

@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
@interface MyAnnotation {
    String   name();
    String   version();
}

class Test{
    int i;

    @MyAnnotation(name="Fun", version="1.0.0")
    public void fun(){
        System.out.println("Super Class");
    }
}

class SubTest extends Test{
    int i;

    @MyAnnotation(name="Fun", version="1.0.1")
    public void fun(){
        System.out.println("Sub Class");
    }
}

public class file {
//    public static void main(String[] args) {
//        FileInputStream ins = null;
//        FileOutputStream outs = null;
//        try {
//            File infile = new File("C:\\Users\\Gaurav\\Desktop\\java1.txt");
//            File outfile = new File("C:\\Users\\Gaurav\\Desktop\\java2.txt");
//
////            FileInputStream infile = new FileInputStream("C:\\Users\\Gaurav\\Desktop\\java1.txt");
////            FileOutputStream outfile = new FileOutputStream("C:\\Users\\Gaurav\\Desktop\\java2.txt");
//            ins = new FileInputStream(infile);
//            outs = new FileOutputStream(outfile);
//            byte[] buffer = new byte[1024];
//            int length;
////            infile.read(buffer);
////            outfile.write(buffer);
//
//            while ((length = ins.read(buffer)) > 0) {
//                outs.write(buffer, 0, length);
//            }
//            ins.close();
//            outs.close();
//            System.out.println("File copied successfully!!");
//        } catch(IOException ioe) {
//            ioe.printStackTrace();}
////        } catch (FileNotFoundException exception) {
////            System.out.println(exception);
////        }
//    }
    public static void main(String[] args) {
        Test t = new Test();
//        t.fun();
//        t = new SubTest();
//        t.fun();
        try {
            System.out.println("Superclass Function Annotations: ");
            Method m = t.getClass().getMethod("fun");
            MyAnnotation m1 = m.getAnnotation(MyAnnotation.class);
            System.out.println("Function is: " + m1.name());
            System.out.println("Version is: " + m1.version());

            System.out.println("\nOverriden Function Annotations: ");
            t = new SubTest();

            m = t.getClass().getMethod("fun");
            m1 = m.getAnnotation(MyAnnotation.class);
            System.out.println("Function is: " + m1.name());
            System.out.println("Version is: " + m1.version());

        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }
    }
}