//We can create abstract class which can have abstract methods and concrete methods.
//Abstract class cannot be instantiated.
//Abstract method is a method which is declared without any implementation.
//If a class has at least one abstract method, then the class must be declared abstract.
//A class that extends an abstract class must implement all the abstract methods of the abstract class.
//If we want to create a method which can be implemented in multiple classes, then we can create an interface.
//Interface is a collection of abstract methods.
//A class can implement multiple interfaces.
//Interface methods are by default abstract and public.
//Interface variables are by default public, static and final.
interface computer
{
    public void compile(); // abstract method
}
//Since we are using interface we cannot use extends keyword we have to use implements keyword
//abstract class computer
//{
//    public abstract void compile(); // abstract method
//}
class desktop implements computer
{
    public void compile()
    {
        System.out.println("Compiling code faster");
    }
}
class laptop implements computer
{
    public void compile()
    {
        System.out.println("Compiling code");
    }
}

class devoloper
{
    public void coding(computer cp)
    {
        System.out.println("Coding on laptop");
        cp.compile();
    }
}
public class abstract_class_interfaces {
    public static void main(String[] args) {
        System.out.println("Abstract class and Interfaces");

        devoloper d = new devoloper();
        //laptop l = new laptop();
        //d.coding(l);

        //desktop dt = new desktop();
        //d.coding(dt); // we cannot pass desktop object to coding method as it expects laptop object
        // thatswhy we will crete an interface and implement it in both classes
        computer c = new laptop();
        d.coding(c);
        computer c2 = new desktop();
        d.coding(c2);
    }
}
