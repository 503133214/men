package LOL;

public class Hero {

    String name; //姓名

    float hp; //血量

    float armor; //护甲

    int moveSpeed; //移动速度

    void  keng(){
        System.out.println("坑队友！");
    }
    float getArmor(){
        return armor;
    }
    void addSpeed(int speed){
        //在原来的基础上增加移动速度
        moveSpeed = moveSpeed + speed;
    }
    void lengendary(){

    }
    float getHp(){
        return hp;
    }
    void recovery(float blood){
        hp = hp + blood;
    }
    public static void main(String[] args) {
        Hero garen =  new Hero();
        garen.name = "盖伦";
        garen.hp = 616.28f;
        garen.armor = 27.536f;
        garen.moveSpeed = 350;
        garen.addSpeed(100);
        garen.keng();
        Hero teemo =  new Hero();
        teemo.name = "提莫";
        teemo.hp = 383f;
        teemo.armor = 14f;
        teemo.moveSpeed = 330;
    }

}
