inherit NPC;
void create()
{
        string *names = ({"小青蛇","小绿蛇","小花蛇"}); 
        set_name( names[random(sizeof(names))], ({ "little snake","snake"}));
        set("vendetta_mark","snake");
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 20);
        set("long", "这是一条小蛇。\n");
       set("vendetta/authority",1);
        set("str", 20);
        set("cor", 100);
        set("cps", 22); 
        set("max_qi", 10000);
        set("max_jing", 5000);
        set("max_neili", 5000);
        set("fle",40);
        set("resistance/gin",25);
        set("resistance/sen",25);
        set("attitude", "peaceful");
				//set("chat_chance", 2);
        //set("chat_msg", ({
        //                "小熊拱了拱你的脚。\n"
        //}) ); 
        set("limbs", ({ "头部", "身体", "尾巴", "七寸" }) );
        set("verbs", ({ "bite" }) ); 
        set("combat_exp", 1000000);
        set("bellicosity", 5 );
        
        set_temp("apply/attack", 500);
        set_temp("apply/dodge", 1000);
        set_temp("apply/unarmed_damage", 20);
        setup();
        carry_object(__DIR__"obj/snake_skin");
} 
