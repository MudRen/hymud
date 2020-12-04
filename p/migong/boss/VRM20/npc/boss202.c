#include <ansi.h>

inherit BOSS;
int boss_attack();
int boss_changeforce();

void create()
{
	int lev;
	set_name( HIB "��������" NOR, ({ "tiehua baozhu", "shuanglong", "boss" }) );
	set("long", HIB "���������������ˣ����������������ͻ����õĳǱ�������������һʱ"
	"�ĺ���������μ�ı�����ִ������峾���Ӷ������ղص������䱦����������������С�\n"NOR);
	
	set("title",  HIW"ʥ����ʿ"NOR);
	set("gender",  "����");
	set("age", 40);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	
	set("dex",180);
	set("con",180);
	set("int",180);
	set("str",180);
	set("vendetta/authority",1);
	set("combat_exp", 120000000);
	set("level", 20);
	set("qi", 3500000);
	set("max_qi", 3500000);
	set("jing", 3500000);
	set("max_jing", 3500000);
	set("neili", 2500000);
	set("max_neili", 2500000);
	set("jiali",200);
	
	set("chat_chance", 5);
	set("chat_msg", ({
	        HIR "����������ݺݵĶ�����˵����Ҫ��ȡ����ȹ�����һ�أ�\n" NOR,
	}));
	
	set_temp("apply/attack", 400);
	set_temp("apply/damage", 6000);
	set_temp("apply/armor", 6000);
	set_temp("apply/defence",300);

	lev = 1000 + random(500);
	
	set_skill("force", lev);
	set_skill("hunyuan-yiqi", lev);
	set_skill("dodge", lev);
	set_skill("shaolin-shenfa", lev);
	set_skill("unarmed", lev);
	set_skill("cuff", lev);
	set_skill("jingang-quan", lev);
	set_skill("strike", lev);
	set_skill("parry", lev);
	set_skill("yijinjing", lev);
	set_skill("buddhism",500);
	set_skill("yizhi-chan", lev);	
	set_skill("finger", lev);	
	set_skill("kurong-changong",lev);
	set_skill("duanjia-sword",lev);
	set_skill("jinyu-quan",lev);
	set_skill("wuluo-zhang",lev);
	set_skill("feifeng-whip",lev);
	set_skill("sun-finger",lev);
	set_skill("yiyang-zhi",lev);
	set_skill("tiannan-step",lev);
	set_skill("six-finger",lev);
	
	set("chat_chance_combat", 95);

	boss_changeforce();
	

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
    "TZ&0"   :  1800,
    "TZ&1"   :  1400,
    "TZ&2"   :  1200,	
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

int boss_changeforce()
{
	//�л�˫�ڹ�
	if (random(6)>=3)
	{
		map_skill("cuff", "jingang-quan");
		map_skill("dodge", "shaolin-shenfa");
		map_skill("finger", "yizhi-chan");
		map_skill("force", "yijinjing");
		map_skill("unarmed","yizhi-chan");
		map_skill("parry","yizhi-chan");

		set("chat_msg_combat", ({
			(: perform_action, "cuff.fumo" :),
			(: perform_action, "cuff.jin" :),
			(: perform_action, "cuff.jin" :),
			(: perform_action, "cuff.jin" :),
			(: perform_action, "cuff.jingang" :),
			(: perform_action, "cuff.qixing" :),
			(: perform_action, "finger.dian" :),
			(: perform_action, "finger.jingmo" :),
			(: perform_action, "finger.jingmo" :),
			(: perform_action, "finger.jingmo" :),
			(: exert_function, "jiuyang" :),
	      	    (: boss_attack :),
		        (: boss_attack :),
		        (: boss_attack :),
		}));
	}
	else
	{
		map_skill("cuff", "jinyu-quan");
		map_skill("dodge", "tiannan-step");
		map_skill("finger", "six-finger");
		map_skill("force", "kurong-changong");
		map_skill("unarmed","six-finger");
		map_skill("parry","six-finger");

		set("chat_msg_combat", ({
			(: perform_action, "finger.liumaijingshen" :),
			(: perform_action, "finger.zong" :),
			(: perform_action, "finger.zong" :),
			(: perform_action, "finger.zong" :),
			(: perform_action, "finger.zongheng" :),
			(: perform_action, "finger.qi" :),
			(: perform_action, "cuff.jin" :),
			(: perform_action, "cuff.jin" :),
	      	    (: boss_attack :),
		        (: boss_attack :),
		        (: boss_attack :),
		}));	
	}
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

int boss_attack()
{
	if (this_object()->is_busy()) return 1;
	if (!this_object()->is_busy()) this_object()->start_busy(2);
	message_vision(HIB "$N" HIR "���һ��������ն���� \n" NOR, this_object());
	
	remove_call_out("hurting");
	call_out("hurting", 1);
	return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision("$N" HIY "������������������裬���ŭ�������׼��𣬺�Ȼ����ʧ���Ѿõġ�����ն���� \n", this_object());
                       
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
       
       boss_changeforce();
        return 1;
}


