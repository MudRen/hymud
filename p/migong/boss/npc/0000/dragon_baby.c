#include <ansi.h>
#include <combat.h>
inherit BOSS; 


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
        set("max_qi", 50000);
        set("max_jing", 55000);
        set("max_neili", 55000);
        set("attitude", "peacefull");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 7000000);
        set("bellicosity", 100 );
        
   set_temp("apply/attack", 100);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/defence",100);
      set_skill("dodge", 500);
      set_skill("force", 500);
      set_skill("unarmed", 500);
      set_skill("dragon",850);
      set_skill("spells",850);
     set_skill("magic-old",800);
      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
 (: do_attack :),
 (: do_attack :),
 }) );


  set("bonus", random(300)+100);
        setup();
        carry_object(__DIR__"obj/dragon_skin");
}
void init()
{
        object me, ob;

        ::init();
        if (! interactive(me = this_player()))
                return;
        
        if( !me->is_character() || me==this_object() || !me) return;
        if(me->query("vendetta/authority")) return;
        if(!userp(me)) return;
        
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
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