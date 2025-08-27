import com.goving.learning.app.*;
public class packages_access_modifiers {
    //In java, package are jar files which contains classes and interfaces.
    //We can create our own package and import it in other classes.
    public static void main(String[] args) {
        System.out.println("Packages and Access Modifiers");
        A_package a = new A_package();
        System.out.println(a.num); //default access modifier, can be accessed within the same package
    }
}
