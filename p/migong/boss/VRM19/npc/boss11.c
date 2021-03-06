#include <ansi.h>
inherit BOSS;

int boss_init(object me);
int boss_zhaohuan(object me);
int boss_attack2();

void create()
{
        set_name( HIY"穷奇" NOR, ({ "qiong qi", "qiongqi" }) );
        set("long", HIY "传说中抑善扬恶的恶神，它的大小如牛、外形象虎、披有刺猬
        的毛皮、长有翅膀，穷奇的叫声象狗，靠吃人为生！\n\n" NOR);

        set("race", "野兽");
        set("gender", "雄性");
        set("age", 10000);
        set("no_get", 1);
        set("shen_type", 0);
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set("dex",400);
	set("con",400);
	set("int",400);
	set("str",400);
		set("nickname",HIR"上古神兽"NOR);
	set("combat_exp", 100000000);
	set("level", 18);
		set("qi", 3800000);
		set("max_qi", 3800000);
		set("jing", 3800000);
		set("max_jing", 3800000);
		set("neili", 3000000);
		set("max_neili", 3000000);
		set("jiali", 20000);
	set("vendetta/authority",1);
	
	set_skill("dodge", 1200);
	set_skill("force", 1200);
	set_skill("unarmed", 1200);
	set_skill("dragon",1250);
	set_skill("spells",1250);
	set_skill("magic-old",1250);
	map_skill("unarmed", "dragon");
	
	map_skill("dodge", "dragon");
	map_skill("spells", "magic-old");
	      set_skill("taiji-shengong", 800);
      map_skill("force", "taiji-shengong");
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.penhuo" :),
		(: perform_action, "unarmed.tuwu" :),
		(: perform_action, "unarmed.yaoyao" :),
			(: boss_attack2 :),
			(: boss_attack2 :),
			(: boss_attack2 :),
	}));
	set_temp("apply/dodge", 200);
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 6600);
	set_temp("apply/armor", 6600);
	set_temp("apply/defence",200);
	
	// 物品奖励
	set("bonus", random(18000)+18000);
	set("killer_reward", ([
		"FI&/clone/box/gbox"   :   10000,
		"RI&10"   :   8000,
		"GE&5"   :  8000,
		"KS&3"   :   8000,
		"BL&3"   :  8000,
		"RI&60"   :   5000,
		"GE&6"   :  6000,
		"JD&7"   :  6000,
		"YC&4"   :  6000,
		"WG&4"   :  6000,
		"KS&7"   :  3600,
		"BL&8"   :  3600,
		"YW&5"   :  3600,
		"YA&5"   :  3600,
		"TW&300"   :  3000,
		"TA&300"   :  3000,
		"TZ&0"   :  2600,
		"TZ&1"   :  2300,		
	]));
	
	setup();
	carry_object("/clone/money/gold")->set_amount(500);
}



void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(2);
this_object()->delete_temp("boss_attack2");
        call_out("hunting",0);
	message_vision(HIB "$N" HIG "怒吼：都说我是抑善扬恶的恶神，但你们真能分清楚善恶么！！ \n" NOR, this_object());

        }
this_object()->delete_temp("boss_attack2");
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


int boss_attack2()
{	
if (!this_object()->query_temp("boss_attack2"))
{
message_vision(HIR "$N" HIR "一声长吼：善恶是非，准备战斗吧！！！ \n" NOR, this_object());
		remove_call_out("boss_zhaohuan"); //5秒后召唤小怪
		call_out("boss_zhaohuan", 5);
this_object()->set_temp("boss_attack2",1);
}
	return 1;
}

int boss_init(object me)
{	
	message_vision(HIB "$N" HIG "怒吼：都说我是抑善扬恶的恶神，但你们真能分清楚善恶么！！ \n" NOR, this_object());
	remove_call_out("kill_ob");
	call_out("kill_ob", 0, me);
}

int boss_zhaohuan(object me)
{
	object obj1,obj2;
	int dam, dam1,i , num;
	object *inv;
	message_vision(HIB "$N" HIG "长啸一声：来吧，都来陪他们玩玩吧！！ \n" NOR, this_object());
	message_vision(HIY "突然间乌云密布，雷鸣闪电，云层中似乎出现了两个神兽护法，"
		"穷奇趁此时突然用力吸气，你感觉快被它吞进口中。\n" NOR,
	this_object());
	
	inv = all_inventory(environment(this_object()));        

	num = sizeof(inv);       
	if (num < 1) num = 1;
	if (num > 5) num = 5;
	
	dam = 16000 / num;
	if(objectp(present("shenshou hufa", environment(this_object()))))
	{
		dam = dam * 2;//有护法存在就伤害加倍
	}
	for (i=sizeof(inv)-1; i>=0; i--)
	{
		if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object()))
		{                        
			dam1 = dam - inv[i]->query_temp("apply/reduce_damage");
			if (dam1 <0) dam1 = 0;
			inv[i]->apply_condition("new_poison6", 5);
			inv[i]->receive_damage("qi", dam1); //不考虑减伤的话，伤害最低也有2000（组队情况下，不组队伤害单独承受）
			inv[i]->receive_damage("jing", dam1/2);  //不考虑减伤的话，伤害最低也有1000（组队情况下，不组队伤害单独承受），主要伤气血，精气来源不多
			inv[i]->receive_wound("qi", dam1);
			inv[i]->receive_wound("jing", dam1/2);
			COMBAT_D->report_status(inv[i], 1);
		}
	}
	if (!present("shenshou hufa 1", environment(this_object())))
{
	obj1 = new(__DIR__"beast1");
	obj1->move(environment(this_object()));
	obj1->kill_ob(me);
}
	if (!present("shenshou hufa 2", environment(this_object())))
{
	obj2 = new(__DIR__"beast1");
	obj2->move(environment(this_object()));
	obj2->kill_ob(me);
}	
	remove_call_out("boss_zhaohuan"); //60秒后召唤小怪
	call_out("boss_zhaohuan", 60, me);
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{

        if (ob->query("shen",1)==0) return 0;
  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
        ob->apply_condition("new_poison6", 3);
        return HIY"$N觉得被打过的地方闪过一道光华！"NOR;
}

		
		if (ob->query("shen",1)> 0) //打中好人回血，打中坏人反受伤害
		{		              
	        me->receive_curing("qi", ob->query("max_qi")/30);
	        me->receive_curing("jing", ob->query("max_jing")/30);
	  ob->apply_condition("new_poison6", 5);
	        return HIY"$N大笑：我要吸你的血！！$n只觉得血气逆流要离身而去，而$N好像又恢复了点体力！"NOR;
	    }
		else
		{	
	        me->receive_damage("qi", random(8888)+100);
	        me->receive_wound("qi", random(8888)+100);
		      me->receive_damage("qi", random(8888)+100);
	        me->receive_wound("jing", random(8888)+100);
 	        return HIY"$N觉得全身像被针扎了一样刺痛，血气逆流，变得越来越虚弱！"NOR;
		}
}

mixed ob_hit(object me, object victim, int damage, int damage_bonus, int factor)
{
        string result;
        if (victim->query("shen",1)==0) return damage;
	if (victim->query("shen",1)> 0) //好人增加攻击，坏人减少攻击
	{
		damage_bonus+=damage/3;
		result = HIG"$N一招命中，$n吃痛怒吼：是非善恶，你就能分的清楚么？\n"NOR;                      
	}
	else
	{	
		damage_bonus-=damage/3;
		result = HIG"$n狞笑：本是同根生，相煎何太急！$N只觉得大部分的攻击被吸收了！\n"NOR;                      
	}
        message_vision(result,me,victim);
        return damage;
}

