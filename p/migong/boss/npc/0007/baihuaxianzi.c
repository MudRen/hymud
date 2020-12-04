// This program is a part of NT mudlib
// boss ģ��

#include <ansi.h>


inherit BOSS;

int big_blowing();

void create()
{
	set_name(HIM "�ٻ�����" NOR, ({ "baihua xianzi", "baihua", "xianzi" }) );
	set("gender", "Ů��");
	set("age", 22);
	set("per", 32);
	set("long", 
HIM"����ĸ�ĵ��ӡ�����ĸ֮������˾������������Ⱥ��֮����
�����϶����������ݺ������ط����������������������
��㺮�����������ơ��ٻ���Ϊ�����˼䣬��һ��Һ��\n\n"NOR);

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);

        set("combat_exp", 70000000);
        set("level", 70);
        set("qi", 1900000);
        set("max_qi", 1900000);
        set("jing", 1900000);
        set("max_jing", 1900000);
        set("neili", 1980000);
        set("max_neili", 1980000);
        set("jiali", 2000);

        set("chat_chance", 5);
        set("chat_msg", ({
                HIM "�����д���һ����磡��������ߣ�\n" NOR,
                HIM "�����д���һ����磡�������˹�ȥ��\n" NOR,
        }));

    set_skill("dodge", 500);
      set_skill("force", 500);
      set_skill("unarmed", 500);
      set_skill("dragon",550);
      set_skill("spells",550);
      set_skill("claw", 220);
        set_skill("throwing", 220);
        set_skill("goplaying", 100);
        set_skill("luteplaying", 100);
        
        set_skill("painting", 100);
        set_skill("medicine", 100);
        set_skill("construction", 100);
        set_skill("horticulture", 100);
        set_skill("dramaturgy", 100);

	set_skill("yangyanshu",780);
	set_skill("force", 200);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand",350);
	set_skill("strike", 250);
        set_skill("sword",250);
	set_skill("sword",200);
	set_skill("strike", 260);
	set_skill("sword", 260);
	set_skill("hand", 360);
	set_skill("qingyun-shou",780);
	set_skill("panyang-zhang",780);
	set_skill("liuyue-jian",780);

	set_skill("wuzhan-mei",780);
	set_skill("zhemei-shou",780);
	set_skill("liuyang-zhang",780);
        set_skill("tianyu-qijian",780);
	set_skill("yueying-wubu",780);
	set_skill("bahuang-gong", 680);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
        map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
        map_skill("sword","tianyu-qijian");

        prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.kuangwu" :),
                	(: perform_action, "sword.qing" :),
                		(: perform_action, "sword.ju" :),
                (: big_blowing :),
                (: big_blowing :),                	               
                (: perform_action, "sword.san" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "dodge.yueguangruying" :),                
        }));

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 600);
        set_temp("apply/armor", 600);
        set_temp("apply/defence",100);
        
        // ��Ʒ����
        // ��Ʒ����
	        set("bonus", random(70000)+5000);
	set("killer_reward", ([
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&3"   :  8000,
               "KS&3"   :   8000,
                "BL&3"   :  8000,
                "RI&60"   :   4000,
                "GE&5"   :  4000,
                "JD&6"   :  4000,
                "YC&3"   :  4000,
                "WG&3"   :  4000,
               "KS&6"   :   500,
                "BL&6"   :  500,
                "YW&5"   :  500,
                "YA&5"   :  500,
                "TW&480"   :  1000,
                "TA&480"   :  1000,
"TZ&0"   :  450,
	]));

        setup();
        	carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/money/gold")->set_amount(200);
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

int big_blowing()
{
        message_vision(HIB "$N" HIM "ͻȻ�������ĵ�һЦ����\n" NOR, this_object());
if (this_object()->is_busy()) this_object()->start_busy(1);
        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIB "$N" HIM "�����д���һ����磡�������˹�ȥ������\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 27000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {
                        dam -= inv[i]->query_temp("apply/reduce_wind");
                        if (dam <0) dam = 0;
                        inv[i]->start_busy(2);
                        inv[i]->receive_wound("qi", dam);
                        inv[i]->receive_wound("jing", dam/3);
                        COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        
        damage = 3000 + random(3000);
        damage -= ob->query_temp("apply/reduce_fire");
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIB "$N" HIB "���١���һ���ų�һ���꣬��ʱ��$n"
               HIB "ʧȥ���ң����������Ż��С�\n" NOR;
}

