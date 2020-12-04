#include <ansi.h>
#include <combat.h>
inherit NPC; 


void do_attack();
void create()
{
        set_name("С��", ({ "dragon baby", "dragon" }) );
        set("vendetta_mark","dragon");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 50);
        
        set("long", "�ֺ�����С����\n");
        
        set("str", 60+random(20));
        set("con", 52);
        set("dex", 20);
        set("fle",100);
        set("resistance/gin",30);
        set("resistance/sen",30);
        set("resistance/qi",30);
        set("no_curse",1);
        set("max_qi", 30000);
        set("max_jing", 15000);
        set("max_neili", 15000);
        set("attitude", "peacefull");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: do_attack :)
        }) ); 
        set("combat_exp", 6000000);
        set("bellicosity", 100 );
        
        set_temp("apply/attack", 500+random(500));
        set_temp("apply/unarmed_damage",100+random(100));
        set_temp("apply/armor", 600+random(600)); 
        setup();
        carry_object(__DIR__"obj/dragon_skin");
}

void do_attack() 
{
	object *enemies,enemy;
	string msg;
	int be_damaged;
	enemies = query_enemy();
	if (!enemies || sizeof(enemies)==0)
			return;
	enemy = enemies[random(sizeof(enemies))];
	add_temp("apply/attack",300);
	add_temp("apply/damage",300);
	msg = HIM"$NͻȻһת����β��$nɨ����\n"NOR;
	message_combatd(msg, this_object(), enemy);
	COMBAT_D->do_attack(this_object(),enemy, 0, 0);
	add_temp("apply/attack",-300);
	add_temp("apply/damage",-300);
	start_busy(2);
}