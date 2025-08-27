class Keyboard{
    private int keys;
    private String color;

    public int getKeys() {
        return keys;
    }

    public void setKeys(int keys) {
        this.keys = keys;
    }
    // Constructor
    Keyboard(int keys, String color){
        this.keys = keys;
        this.color = color;
    }

    void pressed(){
        System.out.println("Key is pressed"+ keys + " " + color);
    }

    void throwit(){
        System.out.println("Keyboard is thrown");
    }
}

public class L4_OOPs_cons {
    public static void main(String[] args) {

    Keyboard keyborad_obj = new Keyboard(104 , "Black");
    keyborad_obj.pressed();
    keyborad_obj.throwit();

    keyborad_obj.setKeys(105);
    System.out.println("Updated keys: " + keyborad_obj.getKeys());
}
}
