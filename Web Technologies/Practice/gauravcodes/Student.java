package javabean;

public class Student implements java.io.Serializable {
    private int id;
    private String name;
    private boolean enrolled;

    public Student() {
    }

    public void setID(int id) {
        this.id = id;
    }

    public int getID() {
        return id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setEnrolled(boolean enrolled) {
        this.enrolled = enrolled;
    }

    public boolean isEnrolled() {
        return enrolled;
    }
}
