public class exception_handling {
    public static void main(String[] args) {
        //Error and Exception
        //Error are irrecoverable like memory overflow, stack overflow etc.
        //Exception are recoverable like file not found, array index out of bound etc.
        //Exception handling is done using try, catch and finally block.
        //try block contains the code which may throw an exception.
        //catch block contains the code to handle the exception.
        //finally block contains the code which will be executed whether an exception is thrown or not.
        int i=10;
        int j=12;
        int nums[] = {1,2,3,4,5};
        int result=0;
        result=i/j;
        try{
            
            result=i/j;
            if(result==0){
                throw new ArithmeticException("Result is zero");
            }
            System.out.println("Accessing element: "+nums[5]);
        }
        catch(ArithmeticException e){
            System.out.println("Cannot divide by zero");
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Array index out of bound");
        }
        catch(Exception e){
            System.out.println("Some other exception occurred");
        }
        finally{
            System.out.println("This block is always executed");
        }
        System.out.println("Result: "+result);
    }
}
