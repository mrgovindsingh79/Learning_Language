class A extends Thread{
    public void run(){
        for(int i=0;i<10;i++){
            System.out.println("Hi");
            try{
                Thread.sleep(10);
            }catch(InterruptedException e){
                System.out.println(getName());
            }

        }
    }
}
class B extends Thread{
    public void run(){
        for(int i=0;i<10;i++){
            System.out.println("Hello");
            try{
                Thread.sleep(10);
            }catch(InterruptedException e){
                System.out.println(getName());
            }
        }
    }
}
public class L10_threads {
    public static void main(String[] args) {
        System.out.println("Threads in Java");
        A obj1 = new A();
        B obj2 = new B();  
        obj1.setPriority(Thread.MAX_PRIORITY);
        obj1.start();
        obj2.start();
    }
}
