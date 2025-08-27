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
}

public class L3_OOPs {
    public static void main(String[] args) {
        int num;
        num = 10;

        Keyboard keyborad_obj = new Keyboard();
        keyborad_obj.keys = 104;
        keyborad_obj.color = "Black";
        keyborad_obj.pressed();
        keyborad_obj.throwit();


        //Inheritance
        System.out.println("Inheritance:");
        System.out.println();
        AdvKeyboard advkey = new AdvKeyboard();
        advkey.keys = 105;
        advkey.color = "White";
        advkey.backlight = 3;
        advkey.type = "RGB";
        advkey.pressed();
        advkey.lighton();
    }
}
