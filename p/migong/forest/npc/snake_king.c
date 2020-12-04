#include <ansi.h>
inherit NPC;
void do_chan();
void do_dot();
void create()
{
        string *names = ({"�ϰ�����","�̻�����","�ڹ�����"}); 
        set_name( names[random(sizeof(names))], ({ "snake king","snake"}));
        set("vendetta_mark","snake");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 60);
        set("long", "����һ�����ߡ�\n");
      
        set("str", 80);
        set("cor", 100);
        set("cps", 22); 
        set("fle",70);
        set("resistance/gin",55);
        set("resistance/sen",55);
        set("max_qi", 20000);
        set("max_jing", 10000);
        set("max_neili", 10000);
        set("attitude", "peaceful");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	        (: do_dot() :),
        }) ); 
        set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
        set("verbs", ({ "bite" }) ); 
        set("combat_exp", 6000000);
        set("bellicosity", 5 );
        
        set_temp("apply/attack", 1000);
        set_temp("apply/dodge", 2000);
        set_temp("apply/unarmed_damage", 30);
        setup();
        carry_object(__DIR__"obj/snake_egg");
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

void do_dot() {
		object *enemies,enemy;
		string msg;
		int be_damaged;
		enemies = query_enemy();
		if (!enemies || sizeof(enemies)==0)
				return;
		enemy = enemies[random(sizeof(enemies))];
		msg = HIG"\n$N���һ�ڶ�����$n��ס��\n"NOR;
		//msg+= HIR"$n���˾綾��\n"NOR;
                message_combatd(msg,this_object(),enemy);
                call_out("take_eff",1, enemy);
		//enemy->add_dot(500,4,"qi",this_object());
		start_busy(1);
		
}
void take_eff(object enemy,object me) {
                if (! enemy || environment(enemy) != environment() ||
                    ! is_fighting(enemy)) return;
		enemy->receive_damage("qi",500+random(500),me);
		enemy->receive_damage("jing",250+random(250),me);
		
		message_combatd(RED"\n$N���ϵľ綾�����ˣ�\n"NOR,enemy);
		COMBAT_D->report_status(enemy);
		
}
