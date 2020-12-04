inherit NPC;

void create()
{
        string *names = ({"С����","С����","С����"}); 
        set_name( names[random(sizeof(names))], ({ "baby bear","bear"}));
        set("vendetta_mark","bear");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 20);
        set("long", "����һֻ�ɰ���С�ܡ�\n");
       set("vendetta/authority",1);
        set("str", 50);
        set("dex", 20);
        set("con", 50);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("combat_exp", 1000000);

        set("attitude", "peaceful");
        set("chat_chance", 2);
        set("chat_msg", ({
                "С�ܹ��˹���Ľš�\n"
        }) ); 
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 

        set_temp("apply/attack", 500);
        set_temp("apply/armor", 1000);
        set_temp("apply/unarmed_damage", 40);
        setup();
        carry_object(__DIR__"obj/bear_skin");
} 
