#include <ansi.h>
inherit NPC;
void use_poison();
void create()
{
        set_name("�߲�����", ({ "colorful bat" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ�߲ʵ�����\n"); 
        set("limbs", ({ "ͷ��", "����", "β��", "���" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 150+random(300));
        set("combat_exp", 2000000+random(2000000));
        set("bellicosity", 3000 );
        set("chat_chance_combat", 10);
        set("apply/attack",400);
        set("apply/dodge",200);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
         
        setup();
}
void use_poison()
{
        object *enemy, ob;
        string msg; 
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))]; 
        tell_object(ob,
"�����һ���ʹ������һ������һ������ӡ�ۡ�\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("qicaibat", 
                (int)this_player()->query_condition("qicaibat")
                + random(15)+10);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}     
