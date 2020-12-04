#include <ansi.h>
#include <combat.h>
inherit NPC;
void do_stun();
void do_attack();
void create()
{
        string *names = ({"����"}); 
        set_name( names[random(sizeof(names))], ({ "tiger king","tiger"}));
        set("vendetta_mark","tiger");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 10);
        set("long", "����һֻ���������Ļ����֡�\n");
      
        set("str", 80);
        set("cor", 120);
        set("cps", 22); 
        set("fle",100);
        set("resistance/qi",60);
        set("max_qi", 20000);
        set("max_jing", 10000);
        set("max_neili", 10000);
        set("attitude", "peaceful");
        set("no_busy",2);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	        (: do_attack() :),
        }) ); 

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("combat_exp", 6000000);
        set("bellicosity", 5 );
        
        set_temp("apply/attack", 1000);
        set_temp("apply/parry", 2000);
        set_temp("apply/unarmed_damage", 70);

        setup();
        carry_object(__DIR__"obj/tiger_xxx");
} 

void do_attack() {
	object *enemies,enemy;
	string msg;
	int be_damaged,i;
	enemies = query_enemy();
	if (!enemies || sizeof(enemies)==0)
			return;
	enemy = enemies[random(sizeof(enemies))];
	msg = HIW"\n$Nü���ſ�����ֻ�ۣ�����һ���׹�����$n��\n"NOR;
	message_combatd(msg,this_object(),enemy);
	if (random(atoi(query("combat_exp"),100))*6>atoi(enemy->query("combat_exp"))) {
			msg = HIW"$n�������������׹���ס��\n"NOR;
			message_combatd(msg,this_object(),enemy);
			enemy->receive_damage("qi",500+random(1000));
			COMBAT_D->report_status(enemy);
	} else {
			msg = HIW"���Ǳ�$n�㿪�ˡ�\n"NOR;
			message_combatd(msg,this_object(),enemy);
	}
	
	
}

varargs void start_busy(mixed new_busy, mixed new_interrupt) 
{
        message_vision(HIY"\n$NͻȻ����һ���쳹ɽ�ֵ�ŭ��$n��ʱ��ʧɫ��\n"NOR,this_object());
        ::start_busy(1);
} 
