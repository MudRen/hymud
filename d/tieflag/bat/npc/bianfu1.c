#include <ansi.h>
inherit NPC;
void use_poison(); 
void create()
{
        set_name(HIC"��������"NOR, ({ "deadly bat" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("yes_carry", 1);
        set("long", "һֻ�ǳ����µ���������\n"); 
        set("limbs", ({ "ͷ��", "����", "β��", "���" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 70+random(150));
        set("arrive_msg", "һ������طɹ���");
        set("leave_msg", "һ������طɿ���");
        set("combat_exp", 200000+random(400000));
        set("bellicosity", 3000 );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
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
                ob->apply_condition("bat_poison",
                (int)this_player()->query_condition("bat_poison")
                + random(3)+5);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}      
