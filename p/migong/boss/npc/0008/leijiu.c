#include <ansi.h>

inherit BOSS;

int showpower1();
int showpower2();
int combatpower();
int powerup();

void create()
{
	set_name("金鹏雷鹫", ({ "jinpeng leijiu", "jinpeng", "leijiu" }) );
	set("name_color","HIY");
	set("gender", "女性");
	set("age", 22);
	set("long", 
HIY"美丽的金鹏鸟，全身金黄，翼长十丈，似乎得道多年。\n\n"NOR);
        
	set("str", 248);
	set("con", 252);
	set("dex", 222);
         set("combat_exp", 70000000);
        set("level", 70);
	set("qi", 1995000);
	set("jing", 1995000);

	set("max_qi", 1995000);
	set("max_jing", 1995000);
	set("jiali",2000);
	set("max_neili",1990000);
	set("neili",1990000);
	set("attitude", "aggressive");

        set("chat_chance", 5);
        set("chat_msg", ({
        	(: showpower1 :) ,
        	(: showpower2 :)
        }) );    

	


	set("combat_exp", 2000000+random(2000000));
        
	set_temp("apply/attack", 20+random(10));
	set_temp("apply/damage",20+random(10));
	set_temp("apply/armor", 20+random(10));
	
 set_temp("apply/attack", 500);
        set_temp("apply/damage", 3600);
        set_temp("apply/armor", 3600);
        set_temp("apply/defence",500);
      set_skill("dodge", 500);
      set_skill("force", 500);
      set_skill("unarmed", 500);
      set_skill("dragon",550);
      set_skill("spells",550);
     set_skill("magic-old",650);
      map_skill("unarmed", "dragon");
     set_skill("taiji-shengong",650);
      map_skill("force", "taiji-shengong");
      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
      
set_skill("unarmed",580);
	set_skill("force", 580);
	set_skill("guiyuan-tunafa",780);
	set_skill("dodge", 300);
	set_skill("strike", 300);
	set_skill("hammer",780);
	set_skill("axe",780);
	set_skill("shuishangpiao",780);
	set_skill("strike", 550);
	set_skill("tiezhang-zhangfa",780);
	set_skill("parry", 200);
	set_skill("cuff", 300);
	set_skill("literate", 100);
	set_skill("tiexue-hammer",380);
	set_skill("duanyun-fu",780);
	set_skill("tongbi-zhang",780);
	set_skill("xuanyuan-axe",780);
	set_skill("liumang-quan",780);
		
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("cuff", "liumang-quan");
	map_skill("parry", "xuanyuan-axe");
	map_skill("axe", "xuanyuan-axe");
	prepare_skill("strike", "tiezhang-zhangfa");
	prepare_skill("cuff", "liumang-quan");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.pofuchenzhou" :),
                (: perform_action, "cuff.guguoshenyou" :),
                (: perform_action, "cuff.luori" :),
                (: perform_action, "axe.kaitianpidi" :),
                (: perform_action, "axe.sanbanfu" :),
                (: perform_action, "axe.jiuqipoxiao" :),
                (: perform_action, "axe.jiuqipoxiao" :),                	
                (: perform_action, "axe.jiuqipoxiao" :),                	                	
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: combatpower :),
		(: combatpower :),
		(: combatpower :),						
		(: command("unwield bigaxe") :),
		(: command("wield bigaxe") :),			
        }) );
        
        set("bonus", random(80000)+5000);
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
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&3"   :  8000,
               "KS&3"   :   8000,
                "BL&3"   :  8000,
                "RI&50"   :   4000,
                "GE&4"   :  4000,
                "JD&5"   :  4000,
                "YC&3"   :  4000,
                "WG&3"   :  4000,
               "KS&6"   :   500,
                "BL&6"   :  500,
                "YW&5"   :  500,
                "YA&5"   :  500,
                "TW&480"   :  1000,
                "TA&480"   :  1000,
"TZ&0"   :  500,
	]));

	setup();
carry_object("/d/tiezhang/npc/obj/axe")->wield();
	carry_object("/clone/money/gold")->set_amount(300);

	// init_npc(this_object(), 3, 8, 0, 100);
// 自动配置NPC属性和技能，第一个参数必须。
// 第一个参数为NPC的OB
// 第二个参数为NPC的门派，1普陀2地府3方寸4月宫5雪山6五庄7龙宫8无底洞其他为基本，不设置为随机门派
// 第三个参数为NPC的技能，按NPC的等级设置(1:50)，缺省或0为不设置
// 第四个参数为NPC的属性和状态等级，按NPC的等级设置，缺省或0为不设置
// 第五个参数为NPC的强度，缺省为100
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
int showpower1()
{
	tell_object(environment(this_object()),HIY"\t一阵金黄色的火焰燃烧起来！你的气息一窒！\n"NOR);
	return 1;
}
int showpower2()
{
	tell_object(environment(this_object()),HIY"\t一阵雷声炸起来！你的气息一窒！\n"NOR);
	return 1;
}

int combatpower()
{
	if (this_object()->is_busy()) this_object()->start_busy(1);
	message_vision( HIY"\n一阵金黄色的火焰燃烧起来！$N双翅一展，阵阵雷声轰鸣！！\n" NOR,this_object());
	remove_call_out("powerup");
	call_out("powerup",random(10)+2);
	return 1;
}

int powerup()
{
	int dam, i , num;
	object *inv;
	message_vision( HIY"\n金黄的火焰向你卷来！你差点晕了过去！！！\n",this_object());
        inv = all_inventory(environment(this_object()));
        num = sizeof(inv);
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        dam = 27000 / num;
        for(i=sizeof(inv)-1; i>=0; i--)
        {
        	if( living(inv[i]) && inv[i] != this_object() )
        	{
        		//dam = dam - inv[i]->query_combat_level("DF_spells");
        		if(dam <0) dam = 0;
        		inv[i]->start_busy(2);
        		inv[i]->receive_wound("qi", dam);
        		inv[i]->receive_wound("jing", dam/3);
        		COMBAT_D->report_status(inv[i],1);
        	}
        }
        return 1;
}

