class student{
    int rollno;
    String name;
    student(int _rollno, String name){
        this.rollno = _rollno;
        this.name = name;
    }

    public String toString(){  //overriding the toString() method
        return "Student [ Roll No: " + rollno + " Name: " + name + " ]";
    }
}

public class L6_string_array {
    public static void main(String[] args) {
        //String is immutable
        String name = "Govind";
        name = name + " Singh";
        System.out.println(name);
        //Here the name is not changed but a new string is created as Govind Singh
        

        //To make string mutable
        StringBuffer sb = new StringBuffer("Govind");
        sb.append(" Singh");
        System.out.println(sb);

        System.out.println("String at:  "+sb.charAt(4));

        //Array
        int nums[] = new int[5];
        nums[0] = 10;
        nums[1] = 20;
        nums[2] = 30;
        nums[3] = 40;
        nums[4] = 50;

        for(int i = 0; i < nums.length; i++){
            System.out.println("Element at index " + i + ": " + nums[i]);
        }

        //enhanced for loop
        System.out.println("Enhanced for loop:");
        for(int num : nums){
            System.out.println(num);
        }

        //Array of objects
        student s1 = new student(1, "Govind");

        //System.out.println("Array of objects:"+s1);
        //Every class in java is inherited from Object class which has a method toString() 
        //which returns the hashcode of the object.
        System.out.println("Array of objects:"+s1.toString());


        //Array of objects
        student students[] = new student[3];
        
        students[0] = new student(101,"govind");
        students[1] = new student(101,"Poonam");
        students[2] = new student(101,"Shiv");
        
        //printing array of objects
        System.out.println("Array of objects:");
        for(student s : students){
            System.out.println(s);
        }

    }
}
