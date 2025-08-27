//Runnable interface
//We can create thread by implementing Runnable interface
class A implements Runnable
{
    public void run()
    {
        for(int i=1;i<=10;i++)
        {
            System.out.println("Thread A: "+i);
            try{
                Thread.sleep(10); // sleep for 500 milliseconds
            }catch(Exception e){
                System.out.println(e);
            }
        }
    }
}
class B implements Runnable
{
    public void run()
    {
        for(int i=1;i<=10;i++)
        {
            System.out.println("Thread B: "+i);
            try{
                Thread.sleep(10); // sleep for 500 milliseconds
            }catch(Exception e){
                System.out.println(e);
            }
        }
    }
}

public class L10_thread_ext {
    public static void main(String[] args) {
        System.out.println("Threads in Java using Runnable interface");
        Runnable obj1 = new A();
        Runnable obj2 = new B();  
        Thread t1 = new Thread(obj1);
        Thread t2 = new Thread(obj2);

        t1.start();
        t2.start();
        
        try {
            t1.join(); // Wait for thread t1 to finish
            t2.join(); // Wait for thread t2 to finish
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Threads have finished execution.");
    }
}
