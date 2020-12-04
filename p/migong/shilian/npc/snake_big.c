#include <ansi.h>
inherit NPC;
void do_chan();
void create()
{
        string *names = ({"����","����","����"}); 
        set_name( names[random(sizeof(names))], ({ "big snake","snake"}));
        set("vendetta_mark","snake");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 20);
        set("long", "����һ�����ߡ�\n");
       set("vendetta/authority",1);
        set("str", 40);
        set("cor", 100);
        set("cps", 22); 
        set("fle",60);
        set("resistance/gin",35);
        set("resistance/sen",35);
        set("max_qi", 15000);
        set("max_jing", 7500);
        set("max_neili", 7500);
        set("attitude", "peaceful");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	        (: do_chan() :),
        }) ); 
        set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
        set("verbs", ({ "bite" }) ); 
        set("combat_exp", 3000000);
        set("bellicosity", 5 );
        
        set_temp("apply/attack", 700);
        set_temp("apply/dodge", 1500);
        set_temp("apply/unarmed_damage", 30);
        setup();
        carry_object(__DIR__"obj/snake_dan");
} 

void do_chan() {
        object *enemies,enemy;
        string msg;
        int be_damaged;
        enemies = query_enemy();
        if (!enemies || sizeof(enemies)==0)
	        return;
        enemy = enemies[random(sizeof(enemies))];
        msg = HIG"\n$N����һ������������ס��$n��\n"NOR;
        message_combatd(msg,this_object(),enemy);
        enemy->start_busy(3);
        start_busy(1);
}