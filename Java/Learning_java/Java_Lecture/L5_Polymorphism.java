class Keyboard{
    int keys;
    String color;

    public void pressed(){
        System.out.println("Signal send "+ keys + " " + color);
    }

    public void throwit(){
        System.out.println("Keyboard thrown");
    }
    
}

class AdvKeyboard extends Keyboard{
    int backlight;
    String type;

    public void lighton(){
        System.out.println("Backlight on "+ backlight + " " + type);
    }
    public void throwit(){   // method overriding
        System.out.println("Keyboard thrown and hit hard");
    }
}

public class L5_Polymorphism {
    public static void main(String[] args) {
       Keyboard advkey = new AdvKeyboard();
       advkey.throwit();
    }
}
