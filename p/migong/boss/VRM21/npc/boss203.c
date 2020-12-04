#include <ansi.h>

inherit BOSS;
int boss_attack();

void create()
{
	int lev;
	set_name( HIB "�嶾����" NOR, ({ "wudu jiaozhu", "wudu", "boss" }) );
	set("long", HIB "�������嶾�����ˣ���˵�嶾�����������������ĺ��������嶾�������书��Ϊ��������\n"NOR);
	set("title",  HIB"�ڰ�ħ��"NOR);
	set("gender",  "����");
	set("age", 40);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	create_family("�嶾��", 1, "����");
	
	set("dex",180);
	set("con",180);
	set("int",180);
	set("str",180);
	set("vendetta/authority",1);
	set("combat_exp", 220000000);
	set("level", 20);
	set("qi", 4000000);
	set("max_qi", 4000000);
	set("jing", 4000000);
	set("max_jing", 4000000);
	set("neili", 4000000);
	set("max_neili", 4000000);
	set("jiali",200);
	
	set("chat_chance", 5);
	set("chat_msg", ({
	        HIR "�嶾������ݺݵĶ�����˵�����������ҵ��嶾����ɣ�\n" NOR,
	}));
	
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 7200);
	set_temp("apply/armor", 7000);
	set_temp("apply/defence",200);

	lev = 1500 + random(500);

	set_skill("force",lev);
	set_skill("wudu-shengong",lev);
	set_skill("dodge",lev);
	set_skill("wudu-yanluobu",lev);
	set_skill("qianzhu-wandushou",lev);
	set_skill("parry",lev);
	set_skill("sword",lev);
	set_skill("wudu-goufa",lev);
	set_skill("poison",300);
	set_skill("literate",300);
	set_skill("finger",lev);
	set_skill("shedu-qiqiao",lev);
	set_skill("wudu-yanluobu",lev);
	set_skill("unarmed",lev);
	set_skill("duji",300);
	set_skill("wudu-goufa",lev);
	set_skill("whip",lev);
	set_skill("chilian-shenzhang",lev);
	set_skill("jueqing-bian",lev);
	set_skill("ruanhong-zhusuo",lev);
	set_skill("dusha-zhang",lev);
	set_skill("lansha-shou",lev);
	set_skill("hand",lev);
	set_skill("strike",lev);
	set_skill("cuff", lev);
	set_skill("jingang-quan", lev);
	set_skill("yijinjing", lev);
	set_skill("hunyuan-yiqi", lev);


	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	map_skill("cuff", "jingang-quan");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	map_skill("poison","shedu-qiqiao");
	map_skill("finger","shedu-qiqiao");
	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("unarmed", "qianzhu-wandushou");
	map_skill("parry", "wudu-goufa");
	map_skill("sword", "wudu-goufa");
	map_skill("whip", "ruanhong-zhusuo");
	
	set("chat_chance_combat", 95);
	set("chat_msg_combat", ({
			(: perform_action, "unarmed.qzwd" :),
			(: perform_action, "unarmed.qzwd" :),
			(: perform_action, "cuff.jin" :),
			(: perform_action, "cuff.jin" :),
			(: perform_action, "finger.huan" :),
			(: perform_action, "dodge.snake" :),
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
		"KS&9"   :   6000,
		"BL&8"   :  6000,
		"RI&60"   :   6000,
		"GE&6"   :  6000,
		"JD&6"   :  6000,
		"YC&4"   :  6000,
		"WG&4"   :  6000,
		"KS&7"   :  6000,
		"BL&8"   :  6000,
		"YW&5"   :  6000,
		"YA&5"   :  6000,
		"TW&300"   :  6000,
		"TA&300"   :  6000,
    "TZ&0"   :  2800,
    "TZ&1"   :  2400,
    "TZ&2"   :  2300,	
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
	message_vision(HIB "$N" HIR "��������������ʾ��ߴ��������������ʱ����Χ���������ŵ��ȳ�ζ����ʹ�����������ġ��嶾���꡿���� \n" NOR, this_object());
	
	remove_call_out("hurting");
	call_out("hurting", 1);
	return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
                               
        inv = all_inventory(environment(this_object()));        
        num = sizeof(inv);       
        for (i=sizeof(inv)-1; i>=0; i--)
		if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object())) num++;
	if (num < 1) num = 1;
	if (num > 5) num = 5;
        
        dam = 30000 / num;

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
	                inv[i]->apply_condition("new_poison5", 8 );
	                inv[i]->apply_condition("new_poison6", 8 );
					inv[i]->apply_condition("snake_poison", 50 );
					inv[i]->apply_condition("wugong_poison",  50 );
					inv[i]->apply_condition("zhizhu_poison", 50 );
					inv[i]->apply_condition("xiezi_poison",  50 );
					inv[i]->apply_condition("chanchu_poison",  50 );

                   	COMBAT_D->report_status(inv[i], 1);
                }
        }

        return 1;
}


mixed hit_ob(object me, object ob, int damage_bouns)
{
	if (random(5)==0)
	{
		if (!ob->is_busy()) ob->start_busy(3);	
		if (me->query("qi") <= me->query("max_qi")*2) me->add("qi",random(3000));
		if (me->query("eff_qi") <= me->query("max_qi")*2) me->add("eff_qi",random(3000));
		 return HIG "$Nʹ���嶾�񹦣�������$n��������Ѫ��ȫ����˺�����˺ܶ࣡!\n";
	}
	return 0;
}