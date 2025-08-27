public class L2_operator_iterator {
    public static void main(String args[])
    {
        int num1 = 10;
        int num2 = 20;

        int result = num1 + num2;
        result = num1 - num2;
        result = num1 * num2;
        result = num1 / num2;
        result = num1 % num2;
        System.out.println("result: " + result);

        if(num1 > num2){
            System.out.println("num1 is greater than num2");
        }
        else if (num1 < num2){
            System.out.println("num1 is less than num2");
        }
        else{
            System.out.println("num1 is equal to num2");
        }

        //Ternary operator
        String res = (num1 > num2) ? "num1 is greater" : "num2 is greater or equal";
        System.out.println(res);


        //switch case
        int day = 3;
        switch(day){
            case 1:
                System.out.println("Monday");
                break;
            case 2:
                System.out.println("Tuesday");
                break;
            case 3:
                System.out.println("Wednesday");
                break;
            default:
                System.out.println("Other day");
        }


        //while loop
        System.out.println("While Loop:");
        int count = 0;
        while(count < 5){
            System.out.println("Count: " + count);
            count++;
        }


        //for loop
        System.out.println("For Loop:");
        for(int i = 0; i < 5; i++){
            System.out.println("i: " + i);
        }
    }
}
