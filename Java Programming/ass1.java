import java.util.ArrayList;

interface UserService {
    void addUser(User user) throws UserAlreadyExistException;

    User getUser(int userId) throws UserAccountIsBlockedException;

    void updateUser(User user);

    void deleteUser(int userID);

    void unblockUser(int userID);

    ArrayList<User> getAllUsers();
}

class User {
    private int id;
    private String name;
    private boolean status;

    public User(int id, String name) {
        setId(id);
        setName(name);
        setStatus(true);
    }

    public User(int id) {
        setId(id);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null)
            return false;

        User user = (User) o;
        return id == user.id;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean isStatus() {
        return status;
    }

    @Override
    public String toString() {
        return "User{" + "id=" + id + ", name='" + name + '\'' + ", status=" + status + '}';
    }
}

class InMemoryUserService implements UserService {
    public static ArrayList<User> users = new ArrayList<>();

    @Override
    public void addUser(User user) throws UserAlreadyExistException {
        if (users.contains(user))
            throw new UserAlreadyExistException(user.getId());
        users.add(user);
    }

    @Override
    public User getUser(int userId) throws UserAccountIsBlockedException {
        User user = null;
        int index = users.indexOf(new User(userId));
        if (index >= 0) {
            user = users.get(index);
            if (!user.isStatus())
                throw new UserAccountIsBlockedException(user.getId());
        }
        return user;
    }

    /* id attribute must be defined of the passed user object */
    @Override
    public void updateUser(User user) {
        if (users.contains(user)) {
            users.set(users.indexOf(user), user);
        }
    }

    @Override
    public void deleteUser(int userId) {
        users.remove(new User(userId));
    }

    @Override
    public void unblockUser(int userID) {
        int indexOfUser = users.indexOf(new User(userID));
        if (indexOfUser >= 0) {
            User user = users.get(indexOfUser);
            user.setStatus(true);
            System.out.println("User unblocked.");
        }
    }

    public ArrayList<User> getAllUsers() {
        return new ArrayList<User>(users);
    }
}

class UserAlreadyExistException extends RuntimeException {
    private int userId;

    public UserAlreadyExistException(int userId) {
        this.userId = userId;
    }

    @Override
    public String getMessage() {
        return String.format("User with userId : " + userId + " already exist\n");
    }
}

class UserAccountIsBlockedException extends Exception {
    private int userId;

    public UserAccountIsBlockedException(int userId) {
        this.userId = userId;
    }

    @Override
    public String getMessage() {
        return String.format("Account having userId : " + userId + " is block.\n");
    }
}

public class ass1 {
    public static void main(String[] args) {
        UserService userService = new InMemoryUserService();

        User user1 = new User(1, "Batman");
        User user2 = new User(2, "Superman");
        User user3 = new User(3, "Flash");
        User user4 = new User(4, "Hulk");

        try {
            userService.addUser(user1);
            userService.addUser(user2);
            userService.addUser(user3);
            userService.addUser(user4);
            System.out.println("Four users added. ");
            printAllUsersList(userService.getAllUsers());
            System.out.println();

            System.out.println("Updating User4 Name to Wonder Woman.");
            user4.setName("Wonder Woman");
            userService.updateUser(user4);
            System.out.println("Current Data in List: ");
            printAllUsersList(userService.getAllUsers());
            System.out.println();

            System.out.println("Getting user by Id : 4");
            User u = userService.getUser(4);
            System.out.println(u);
            System.out.println();

            System.out.println("Removing User of ID 4");
            userService.deleteUser(4);
            System.out.println("After removing ... Data in list: ");
            printAllUsersList(userService.getAllUsers());
            System.out.println();

        } catch (UserAlreadyExistException | UserAccountIsBlockedException exp) {
            System.out.println(exp.getMessage());
        }
    }

    public static void printAllUsersList(ArrayList<User> users) {
        for (User user : users) {
            System.out.println(user);
        }
    }
}

public class file {
    public static void main(String[] args) {
        FileInputStream ins = null;
        FileOutputStream outs = null;
        try {
            File infile = new File("C:\\Users\\Gaurav\\Desktop\\java1.txt");
            File outfile = new File("C:\\Users\\Gaurav\\Desktop\\java2.txt");

            ins = new FileInputStream(infile);
            outs = new FileOutputStream(outfile);
            byte[] buffer = new byte[1024];
            int length;

            while ((length = ins.read(buffer)) > 0) {
                outs.write(buffer, 0, length);
            }

            ins.close();
            outs.close();

            System.out.println("File copied successfully!!");
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }
    }
}
