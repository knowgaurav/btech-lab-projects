// package javabean;

import java.util.*;
import javabean.Student;

public class Test {
    public static void main(String[] args) {
        Student s1 = new Student();

        s1.setID(9064);
        s1.setName("Gaurav Singh");
        s1.setEnrolled(true);

        System.out.println("Student info is: " + s1.getName() + " " + s1.getID() + " " + s1.isEnrolled());
    }
}
