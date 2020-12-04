#include <ansi.h>

inherit BOSS;
int boss_attack();

void create()
{
	int lev;

	set_name( HIY "˫������" NOR, ({ "shuanglong baozhu", "shuanglong", "boss" }) );
	set("long", HIY "������˫�������ˣ���˵�������Ͷγ���������צ�����ֲ��ޣ�����ɽ"
	"�������ħ�ߣ����ɡ�˫�������������������ºú����������֣������н�����ɱ������"
	"�����а����֮�˷�ָ\n" NOR);
	set("title",  HIW"ʥ����ʿ"NOR);
	set("gender",  "����");
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
	        HIR "˫��������ݺݵĶ�����˵���ô�˫����������\n" NOR,
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

	// ��Ʒ����
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
	message_vision(HIY "$N" HIR "����һЦ�����������������������ɣ��� \n" NOR, this_object());
	
	remove_call_out("hurting");
	call_out("hurting", 1);
	return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIY "$N" HIY "��Х���죬�����޹����䣬��������ɫ��â�����Ƶ��ƿձ��裬�ͷ�ҫ�ۡ�"
        "�������˹����ɵ����ܼ��س��ⷭӿ���͡�\n", this_object());
                       
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
		return RED"$N����������������ȡ$n����Ԫ�����ϵ��˺��˺ܶ�!\n"NOR;
	}
	return 0;
}

