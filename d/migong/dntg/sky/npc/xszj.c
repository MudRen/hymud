inherit NPC;
#include "huoyannpc2.h"

void create()
{
   set_name("ڼʥ���",({"xusheng zhenjun","zhenjun","xianguan","xian",}));
   set("long","���𱣻���ʴ�۵��������¼������������ޱȡ�.\n");
   set("per",23);
   set("str",30);
   set_skill("force",160);
   set_skill("dodge",200);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");


	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );
   set("max_neili",1600);
   set("max_mana",2000);
   set("mana",2000);
   set("neili",1600);
   set("mana_factor",80);
   set("force_factor",70);
   set("max_qi",2000);
   set("max_jing",2400);
   set("combat_exp",1400000);
   set("daoheng",800000);
   setup();
	carry_object("/clone/weapon/changjian")->wield();
carry_object(__DIR__"obj/xianpao")->wear();
}
