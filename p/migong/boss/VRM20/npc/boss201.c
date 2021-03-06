#include <ansi.h>

inherit BOSS;
int boss_attack();

void create()
{
	int lev;

	set_name( HIY "双龙堡主" NOR, ({ "shuanglong baozhu", "shuanglong", "boss" }) );
	set("long", HIY "他就是双龙堡主了，传说霹雳剑客段成弼化名九爪神龙阎伯修，将北山"
	"变成武林魔窟，建成“双龙堡”，妄想收罗天下好汉，独霸武林；并横行江湖，杀人如麻"
	"令江湖正邪两道之人发指\n" NOR);
	set("title",  HIW"圣剑骑士"NOR);
	set("gender",  "男性");
	set("age", 60);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	
	set("dex",180);
	set("con",180);
	set("int",180);
	set("str",180);
	set("vendetta/authority",1);
	set("combat_exp", 100000000);
	set("level", 20);
	set("qi", 3200000);
	set("max_qi", 3200000);
	set("jing", 3200000);
	set("max_jing", 3200000);
	set("neili", 2200000);
	set("max_neili", 2200000);
	set("jiali",200);
	
	lev = 1000 + random(500);

	set("chat_chance", 5);
	set("chat_msg", ({
	        HIR "双龙堡主恶狠狠的盯着你说：擅闯双龙堡者死！\n" NOR,
	}));
	
	set_temp("apply/attack", 400);
	set_temp("apply/damage", 6000);
	set_temp("apply/armor", 6000);
	set_temp("apply/defence",300);

	set_skill("necromancy", 380);
	set_skill("force", lev);
	set_skill("xiaowuxiang", lev);
	set_skill("dodge", lev);
	set_skill("shenkong-xing", lev);
	set_skill("unarmed", lev);
	set_skill("yujiamu-quan", lev);
	set_skill("strike", lev);
	set_skill("parry", lev);
	set_skill("cuff", lev);
	set_skill("sword", lev);
	set_skill("mingwang-jian", lev);
	set_skill("lamaism", 380);
	set_skill("literate", 100);
	set_skill("staff", lev);
	set_skill("xiangmo-chu", lev );
	set_skill("strike", lev );
	set_skill("huoyan-dao", lev);
	set_skill("dashou-yin", lev);
	set_skill("xiangmo-chu", lev);
	set_skill("magic", 380);
	set_skill("kwan-yin-spells", 380);
	map_skill("magic", "kwan-yin-spells");
	map_skill("cuff", "yujiamu-quan");
	map_skill("hand", "dashou-yin");
	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("unarmed", "yujiamu-quan");
	map_skill("parry", "huoyan-dao");
	map_skill("sword", "mingwang-jian");
	map_skill("staff", "xiangmo-chu");
	map_skill("strike","huoyan-dao");

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
	(: perform_action, "hand.yin" :),
	(: perform_action, "hand.dashouyin" :),
	(: perform_action, "hand.jingang" :),
	(: perform_action, "strike.yan" :),
	(: perform_action, "strike.xiuluo" :),
	(: perform_action, "strike.honglian" :),
	(: perform_action, "strike.fen" :),
	(: perform_action, "strike.fen" :),
	(: perform_action, "strike.fen" :),
	        (: boss_attack :),
	        (: boss_attack :),
	        (: boss_attack :),
	}));

	// 物品奖励
	set("bonus", random(200000)+5000);
	set("killer_reward", ([
		"FI&/clone/box/gbox"   :   10000,
		"RI&60"   :   6000,
		"GE&6"   :  6000,
		"KS&7"   :   6000,
		"BL&8"   :  6000,
		"RI&60"   :   6000,
		"GE&6"   :  6000,
		"JD&6"   :  6000,
		"YC&4"   :  6000,
		"WG&4"   :  6000,
		"KS&7"   :  5000,
		"BL&8"   :  5000,
		"YW&5"   :  5000,
		"YA&5"   :  5000,
		"TW&300"   :  5000,
		"TA&300"   :  5000,
    "TZ&0"   :  800,
    "TZ&1"   :  400,
    "TZ&2"   :  200,	
	]));
	
	setup();
	carry_object("/clone/money/gold")->set_amount(30+random(800));
	carry_object("/clone/cloth/cloth")->wear();
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

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

int boss_attack()
{
	if (this_object()->is_busy()) return 1;
	if (!this_object()->is_busy()) this_object()->start_busy(2);
	message_vision(HIY "$N" HIR "阴阴一笑：尝尝我无上玄功的厉害吧！！ \n" NOR, this_object());
	
	remove_call_out("hurting");
	call_out("hurting", 1);
	return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIY "$N" HIY "长啸飞天，周身霓光四射，无数道彩色气芒利箭似的破空爆舞，缤纷耀眼。"
        "团团气浪滚滚飞弹，密集地朝外翻涌推送。\n", this_object());
                       
        inv = all_inventory(environment(this_object()));        
        num = sizeof(inv);       
        for (i=sizeof(inv)-1; i>=0; i--)
		if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object())) num++;
	if (num < 1) num = 1;
	if (num > 5) num = 5;
        
        dam = 25000 / num;

        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object()))
                {                        
                      dam -= inv[i]->query_temp("apply/reduce_damage");
                      if (dam <0) dam = 0;
                      inv[i]->receive_damage("qi", dam);
                      inv[i]->receive_damage("jing", dam/3);
                      inv[i]->receive_wound("qi", dam);
                      inv[i]->receive_wound("jing", dam/3);
                      COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
	if (random(5)==0)
	{
		me->add("qi",random(3000));
		if (me->query("eff_qi") < me->query("max_qi"))
		me->add("eff_qi",random(3000));
		return RED"$N运起无上玄功，吸取$n的真元，身上的伤好了很多!\n"NOR;
	}
	return 0;
}

