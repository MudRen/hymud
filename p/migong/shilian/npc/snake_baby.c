inherit NPC;
void create()
{
        string *names = ({"С����","С����","С����"}); 
        set_name( names[random(sizeof(names))], ({ "little snake","snake"}));
        set("vendetta_mark","snake");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 20);
        set("long", "����һ��С�ߡ�\n");
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
        //                "С�ܹ��˹���Ľš�\n"
        //}) ); 
        set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
        set("verbs", ({ "bite" }) ); 
        set("combat_exp", 1000000);
        set("bellicosity", 5 );
        
        set_temp("apply/attack", 500);
        set_temp("apply/dodge", 1000);
        set_temp("apply/unarmed_damage", 20);
        setup();
        carry_object(__DIR__"obj/snake_skin");
} 
