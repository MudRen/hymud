 //TIE2
#include <ansi.h>
inherit NPC;
void use_poison();
void create()
{
        set_name("ˮͰ���ϸ�Ĵ���", ({ "sea snake" }) );
        set("race", "Ұ��");
        set("str",40);
        set("age", 4);
        set("long", "һ��ȫ���ںڣ������ڰ�ˮͰ���ϸ�Ĵ���\n");
        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set("qi",1000);
        set("max_qi",1000);
        set("eff_qi",1000);
        set("jing",700);
        set("max_jing",700);
        set("eff_jing",700);
        set("jing",700);
        set("max_jing",700);
        set("eff_jing",700);
        set_skill("dodge", 100);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("combat_exp", random(999999));
        set("bellicosity", 300 );
        setup();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
} 
void use_poison()
{
        object *enemy, ob;
        string msg; 
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))]; 
        tell_object(ob, HIR+"\n\n"+
name()+"�������ȫ��ʹ��һ�գ���ֻ���������꣢һ��������\n\n" +NOR);
                ob->receive_wound("qi",100);
}
void unconcious()
{
::die();
}   
