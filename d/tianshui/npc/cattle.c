// cattle.c
inherit NPC;
void create()
{
        set_name("����ţ", ({ "cattle" }) );
        set("race", "Ұ��");
        set("age", 40);
        set("long", "����һͷ����ţ��");
        set("attitude", "heroism");
        set("kee", 1000);
        set("max_kee", 1000);
                
        set("gin", 1000);
        set("max_gin", 1000);
        set("sen", 1000);
        set("max_sen", 1000);
        
        set("combat_exp", 300000);
        set("limbs", ({ "ͷ��", "����", "β��","ǰ��", "����"}) );
        set("verbs", ({ "bite","claw" }) );
        set("str",30);
        set("cor",30);
        set("chat_chance", 80);
   
        set_temp("apply/attack", 80);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 40);
        setup();
}