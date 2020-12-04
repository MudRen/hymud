#include <ansi.h>

inherit NPC;

void do_stun();
void create()
{
        string *names = ({"����","����","����"}); 
        set_name( names[random(sizeof(names))], ({ "big bear","bear"}));
        set("vendetta_mark","bear");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 20);
        set("long", "����һֻ���͵��ܡ�\n");
       set("vendetta/authority",1);
        set("str", 100);
        set("dex", 40);
        set("con", 100);
        set("max_qi", 15000);
        set("max_jing", 7500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("combat_exp", 3000000);
        set("attitude", "peaceful");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	        (: do_stun() :),
        }) ); 
        
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 

        set_temp("apply/attack", 1200);
        set_temp("apply/armor", 1000);
        set_temp("apply/unarmed_damage", 60);
        setup();
        carry_object(__DIR__"obj/bear_hand");
} 

void do_stun() 
{
	object *enemies,enemy;
	string msg;
	int be_damaged;
	
	enemies = query_enemy();
	if (!enemies || sizeof(enemies)==0)
	        return;
	enemy = enemies[random(sizeof(enemies))];
	msg = HIC"\n$NͻȻվ���������������Ƴ�$n������\n"NOR;
	message_combatd(msg, this_object(), enemy);
	COMBAT_D->do_attack(this_object(),enemy, 0, 0);
	start_busy(2);
}