// This program is a part of NITAN MudLIB

#include <ansi.h>
inherit BOSS;
//inherit  NPC;

string *first_name = ({ "��żɽׯ"});
string *first_id = ({ "wanou"});
string *name_words = ({ "צ��", "��Ժ", "��ʿ", "����"});
string *id_words = ({ "zhaoya","huyuan","wushi","shiwei"});

void create()
{
	string name;
	int i, j;
	
	i = random(sizeof(first_name));
	name = first_name[i];
	j = random(sizeof(name_words));
	name += name_words[j];
	
	set_name(name, ({ first_id[i]+" "+id_words[j] }) );
	// random_name_color(this_object());
	
	set("gender",  "����");
	set("age", 30);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	set("vrm_guard", 1);
	
	set("dex",60);
	set("con",60);
	set("int",60);
	set("str",60);
	
	set("combat_exp", 8000000);
	set("level", 6);
	set("qi", 50000);
	set("max_qi", 50000);
	set("jing", 30000);
	set("max_jing", 30000);
	set("neili", 30000);
	set("max_neili", 30000);
	set("neili", 30000);
	set("jiali", 200);

	set_temp("apply/attack", 200);
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 500);
	set_temp("apply/armor", 500);
	set_temp("apply/defence",200);
if (random(2)==0)
{
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );

}
else
{
 set_temp("fanzhen",1);
	set_skill("buddhism", 500);
	set_skill("literate", 300);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set_skill("unarmed", 300);
	set_skill("blade", 300);
	set_skill("claw", 300);
	set_skill("club", 300);
	set_skill("cuff", 300);
	set_skill("dodge", 300);
	set_skill("finger", 300);
	set_skill("force", 300);
	set_skill("hand", 300);
	set_skill("parry", 300);
	set_skill("staff", 300);
	set_skill("strike", 300);
	set_skill("sword", 300);
	set_skill("whip", 300);

set_skill("weituo-zhang", 380);
set_skill("shaolin-tantui", 380);
set_skill("jingang-zhang", 380);
set_skill("jimie-zhua", 380);
set_skill("duoluoye-zhi", 380);
set_skill("mohe-zhi", 380);
set_skill("boluomi-shou", 380);
	set_skill("banruo-zhang", 380);
	set_skill("cibei-dao", 380);
	set_skill("damo-jian", 380);
	set_skill("fengyun-shou", 380);
	set_skill("fumo-jian", 380);
	set_skill("hunyuan-yiqi", 380);
	set_skill("jingang-quan", 380);
	set_skill("longzhua-gong", 380);
	set_skill("luohan-quan", 380);
	set_skill("nianhua-zhi", 380);
	set_skill("pudu-zhang", 380);
	set_skill("qianye-shou", 380);
	set_skill("sanhua-zhang", 380);
	set_skill("riyue-bian", 380);
	set_skill("shaolin-shenfa", 380);
	set_skill("weituo-gun", 380);
	set_skill("wuchang-zhang", 380);
	set_skill("xiuluo-dao", 380);
	set_skill("yingzhua-gong", 380);
	set_skill("yijinjing", 380);
	set_skill("yizhi-chan", 380);
	set_skill("zui-gun", 380);
	set_skill("weituo-chu", 380);
	set_skill("ranmu-daofa", 380);
	set_skill("wuying-jian", 380);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "jingang-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "wuying-jian");
	map_skill("whip", "riyue-bian");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
(: perform_action, "cuff.fumo" :),
	(: perform_action, "cuff.jin" :),
		(: perform_action, "cuff.jingang" :),
			(: perform_action, "cuff.qixing" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "sword.wuying" :),
                (: perform_action, "sword.lidichenfo" :),
                (: perform_action, "sword.ruying" :),
                 (: perform_action, "sword.foxing" :),	
                (: exert_function, "jiuyang" :),
                (: exert_function, "tong" :),
                (: exert_function, "roar" :),		 	
                (: exert_function, "chang" :),		 		
                (: exert_function, "jingang" :),		 			
        }) );
}
	set("bonus", random(280)+180);
	set("killer_reward", ([
	      "FI&/clone/box/gbox"   :   300,
	      "TW&180"   :  200,
	      "TA&180"   :  200,
	]));
	
	
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
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
        
mixed hit_ob(object me, object ob, int damage_bouns)
{
	int damage;
  	damage = 200 + random(200);
	ob->receive_wound("qi", damage);
	ob->start_busy(2);

	return "$NͻȻʹ��͵ѧ��ΤһЦ����������$n���õ�������������Ӱ����֪������ô��ź��ˣ�\n" NOR;
}

