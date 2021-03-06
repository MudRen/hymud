// This program is a part of NT mudlib
// boss 模板

#include <ansi.h>


inherit BOSS;

int big_blowing();

void create()
{
	set_name(HIM "百花仙子" NOR, ({ "baihua xianzi", "baihua", "xianzi" }) );
	set("gender", "女性");
	set("age", 22);
	set("per", 32);
	set("long", 
HIM"西王母的弟子。奉王母之命，总司天下名花，乃群芳之主。
因与嫦娥不睦，遭其陷害，被谪凡尘。厄满后独居蓬莱，不
与广寒宫来往，所制“百花酿”为天上人间，第一玉液。\n\n"NOR);

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
                HIM "花丛中吹来一阵香风！差点把你卷走！\n" NOR,
                HIM "花丛中吹来一阵香风！你差点晕了过去！\n" NOR,
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
        
        // 物品奖励
        // 物品奖励
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
        message_vision(HIB "$N" HIM "突然朝你妩媚的一笑！！\n" NOR, this_object());
if (this_object()->is_busy()) this_object()->start_busy(1);
        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIB "$N" HIM "花丛中吹来一阵香风！你差点晕了过去！！！\n" NOR,
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
        return HIB "$N" HIB "“嘿”的一声放出一阵花雨，登时令$n"
               HIB "失去自我，被花雨屡屡击中。\n" NOR;
}

