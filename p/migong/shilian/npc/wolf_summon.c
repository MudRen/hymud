#include <ansi.h>
#include <combat.h>
inherit NPC;
void do_attack();
void create()
{
        string *names = ({"血狼"}); 
        set_name( names[random(sizeof(names))], ({ "blood wolf","wolf"}));
        set("vendetta_mark","wolf");
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 20);
        set("long", "这是一只可怕的血狼。\n");
      
        set("str", 50);
        set("con", 120);
        set("dex", 22); 
        set("fle",50);
        set("resistance/qi",25);
        set("max_qi", 15000);
        set("max_jing", 7500);
        set("max_neili", 7500);
        set("attitude", "peaceful");
         set("vendetta/authority",1);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	        (: do_attack() :),
        }) ); 

        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("combat_exp", 3000000);
        set("bellicosity", 5 );
        
        set_temp("apply/attack", 1000);
        set_temp("apply/dodge", 500);
        set_temp("apply/parry", 500);
        set_temp("apply/unarmed_damage", 80);
        setup();
        //carry_object(__DIR__"obj/wolf_meat");
} 

mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->receive_damage("qi",300+random(300), me);
        victim->receive_wound("qi",200+random(200), me);
        message_combatd(HIW"\n$N"+HIW"锋利的爪子在$n"+HIW"身上留下一道血淋淋的伤口！"NOR,me,victim);
        return;
}      

void do_attack() {
	object *enemies,enemy;
	string msg;
	int be_damaged,i;
	enemies = query_enemy();
	if (!enemies || sizeof(enemies)==0)
			return;
	enemy = enemies[random(sizeof(enemies))];
	msg = HIR"\n$N突然急窜，向$n的咽喉咬去！\n"NOR;
	message_combatd(msg,this_object(),enemy);
if (random(atoi(query("combat_exp"),100))*6>atoi(enemy->query("combat_exp"))) {
			msg = HIR"$n躲闪不及，被咬个正着！\n"NOR;
			message_combatd(msg,this_object(),enemy);
			enemy->receive_damage("qi",500+random(500));
			COMBAT_D->report_status(enemy);
	} else {
			msg = HIY"但是被$n躲开了。\n"NOR;
			message_combatd(msg,this_object(),enemy);
	}
	
	
}