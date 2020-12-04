// This program is a part of NT mudlib
// boss 模板

#include <ansi.h>

inherit BOSS;
//inherit  NPC;
//inherit  NPC;
#include "/d/migong/romnpc2.c"
int boss_attack();

void create()
{
	set_name( HIR "铁罗刹" NOR, ({ "boss killer",  "boss" }) );
	set("long", HIB "他就是女魔。\n\n" NOR);
	set("title",  HIY"女魔"NOR);
	set("gender",  "女性");
	set("age", 30);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	set("per",100);
	set("dex",100);
	set("con",100);
	set("int",100);
	set("str",100);
	
	set("combat_exp", 10000000);
	set("level", 10);
	set("qi", 690000);
	set("max_qi", 690000);
	set("jing", 690000);
	set("max_jing", 690000);
	set("neili", 690000);
	set("max_neili", 690000);
	set("neili", 90000);
	set("jiali", 300);
	

	
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 1000);
	set_temp("apply/armor", 1000);
	set_temp("apply/defence",200);

	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("parry", 300); 
	set_skill("sword",300);
	set_skill("sharen-sword",500);
	set_skill("changquan",500);
	set_skill("shadowsteps",500);
	set_skill("cloudforce",500);
	map_skill("force", "cloudforce");
	map_skill("sword", "sharen-sword");
	map_skill("dodge", "shadowsteps");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
	(: perform_action, "sword.sharenruma" :),
	(: perform_action, "unarmed.yuhuan" :),
	        (: boss_attack :),
	}));
	
    set_temp("apply/reduce_damage", 40);
    set_temp("apply/reduce_busy", 10);
    set_temp("apply/add_busy", 2);
  	set("bonus", random(12000)+5000);
// 物品奖励 说明
// 掉落概率 10000为最大,必掉,5000为1/2机会,数字越小,掉落的可能越少.
// 掉落阵列关键字以 FI 起头表示为掉落某个特定物品
// 掉落阵列关键字以 RI  起头表示为掉落某个戒指 %d为等级(10-60) 
// 掉落阵列关键字以 GE 起头表示为掉落某个宝石 %d为等级(1-8)
// 掉落阵列关键字以 JD 起头表示为掉落某个打造用升级宝石 %d为等级(1-8)
// 掉落阵列关键字以 YC 起头表示为掉落药材 %d为无效参数("随机等级无效)
// 掉落阵列关键字以 WG 起头表示为掉落宝物装备 %d为无效参数
// 掉落阵列关键字以 KS 起头表示为掉落打造用矿石 %d为等级(1-10)
// 掉落阵列关键字以 BL 起头表示为掉落打造用布料 %d为等级(1-10)
// 掉落阵列关键字以 YW 起头表示为掉落打造武器用玉石 %d为等级(1-6)
// 掉落阵列关键字以 YA 起头表示为掉落打造防具用玉石 %d为等级(1-6)
// 掉落阵列关键字以 YW 起头表示为掉落打造武器用玉石 %d为等级(1-6)
// 掉落阵列关键字以 TW 起头表示为掉落打造武器 %d为等级 (0-480)
// 掉落阵列关键字以 TA 起头表示为掉落打造防具 %d为等级(0-480)


set("killer_reward", ([
                "FI&/clone/box/gbox"   :   5000,
                "RI&10"   :   5000,
                "GE&4"   :  5000,
               "KS&3"   :   3000,
                "BL&3"   :  3000,
                "RI&20"   :   1800,
                "GE&3"   :  1800,
                "JD&4"   :  1800,
                "YC&1"   :  1800,
                "WG&1"   :  1800,
               "KS&5"   :   300,
                "BL&5"   :  300,
                "YW&3"   :  200,
                "YA&3"   :  200,
                "TW&180"   :  600,
                "TA&180"   :  600,
"TZ&0"   :  300,
	]));
	
    setup();
    carry_object("/clone/money/gold")->set_amount(20+random(220));
	carry_object(__DIR__"obj/cloth")->wear();
	initlvl(600+random(30),5);
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

int hit_ob(object me, object ob, int damage)
{
	if (me->is_busy()) me->start_busy(1);
me->clear_condition();	

  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
if (random(10)==0)
{
ob->apply_condition("new_poison1", 5); 
}
else if (random(9)==0)
{
ob->apply_condition("new_poison2", 5); 
}
else if (random(8)==0)
{
ob->apply_condition("new_poison3", 5); 
}
else if (random(7)==0)
{
ob->apply_condition("new_poison4", 5); 
}
else if (random(6)==0)
{
ob->apply_condition("new_poison5", 5); 
}
else if (random(5)==0)
{
ob->apply_condition("new_poison6", 5); 
}
        tell_object(ob, HIG "你觉得被打中的地方闪过一阵光华！\n" NOR );
}
}
int big_blowing()
{
if (this_object()->is_busy()) this_object()->start_busy(1);
	this_object()->clear_condition();
        return 1;
}