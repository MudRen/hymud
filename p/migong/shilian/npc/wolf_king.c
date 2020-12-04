#include <ansi.h>
#include <combat.h>
inherit NPC;
void do_summon();
void create()
{
        string *names = ({"��������"}); 
        set_name( names[random(sizeof(names))], ({ "wolf king","wolf"}));
        set("vendetta_mark","wolf");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 1000);
        set("long", "\n");
      
        set("str", 80);
        set("con", 120);
        set("cps", 22); 
        set("fle",100);
        set("resistance/qi",60);
        set("max_qi", 20000);
        set("max_jing", 10000);
        set("max_neili", 10000);
         set("vendetta/authority",1);
        set("attitude", "peaceful");

        set("chat_chance_combat", 80);
		    set("chat_msg_combat", ({
		                (: do_summon() :),
		    }) ); 

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
                set("combat_exp", 6000000);
                set("bellicosity", 5 );
        
        set_temp("apply/attack", 1000);
        set_temp("apply/dodge", 800);
        set_temp("apply/parry", 800);
        set_temp("apply/unarmed_damage", 70);
        setup();
        carry_object(__DIR__"obj/wolf_eye");
} 

mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->receive_damage("qi",400+random(400), me);
        victim->receive_wound("qi",300+random(300), me);
        message_combatd(HIW"\n$N"+HIW"������צ����$n"+HIW"��������һ��Ѫ���ܵ��˿ڣ�"NOR,me,victim);
        return;
}   

void do_summon() {
	object wolf,me,enemy,enemies;
	me = this_object();
	
	message_vision(HIB "\n$N�����Ǻ����ء�໡������ء�໡�����ʱ��ɽ��ҰȺ��������\n" NOR, me); 
	seteuid(getuid());   
	wolf = new(__DIR__"wolf_summon");
	wolf->move(environment(me));
	enemies = me->query_enemy();
	foreach(enemy in enemies) {
	        wolf->kill_ob(enemy);
	        enemy->kill_ob(wolf);
	} 
        message_vision( "\n\n$N��ݺݵ�����������\n" , wolf);
        call_out("leave", 20+random(10), wolf);
        start_busy(2);
}

void leave(object wolf){
        if (! wolf) return;
        message_combatd("\n$NͻȻ��ʧ�ˡ�\n",wolf);
        destruct(wolf);
}
