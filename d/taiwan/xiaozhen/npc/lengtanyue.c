#include <ansi.h>
inherit NPC;
void create()
{
    set_name("冷探月",({"leng tanyue"}));
    set("gender","男性");
    set("age",54);
    set("long","三十年前，[阴煞双凶]是横行绿林的大盗，
    自从投入幽冥一门以来，不再出现江河。\n");
    set("title",YEL"天煞"NOR);
    set("combat_exp",500000);
    set("kee",800);
    set("max_kee",800);
    set("force",800);
    set("max_force",800);
    set("force_factor",25);
    set("food",200);
    set("water",200);
    
    set("inquiry",([
    "幽冥山庄":"你现在呆的地方就是了。\n",
    "道心种魔大法":"我门中无上大法，可惜早几代就失传了.\n",
    ]));
    
        set("shen_type",-1);
    set("chat_chance",3);
    set("chat_msg",({
    CYN"冷探月取出把大砍刀掏起耳朵来.\n"NOR,
    CYN"听说我门中还有位长老,不过谁都没见过.\n"NOR,
    CYN"冷探月添添嘴唇道:他奶奶的,也不来个人给解解馋。\n"NOR,
    }));
    
    set_skill("dodge",50);
    set_skill("parry",50);
    set_skill("unarmed",50);
    set_skill("force",50);
    set_skill("literate",10);

      set("combat_exp", 9999999);
    set("score", random(90000));
    
         set("chat_chance_combat", 90);
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
	set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
    setup();
    add_money("silver",5);
 }
void init()
{
  object ob;
  ::init();
  if (interactive(ob=this_player())&&!is_fighting())  {
  	remove_call_out("greeting");
  	call_out("greeting",1,ob);
     }
  }
void greeting(object ob)
{
   if (!ob||environment(ob)!=environment())  return;
   if (ob->query("family/family_name")!=RED"幽冥山庄"NOR) {
   	kill_ob(ob);
   	return;
     }
   if (ob->query("combat_exp")>500000)
 command("say 您老来啦,宗主等你好久了!\n");
   else   {
 if (ob->query("gender")=="女性")
 command("say 小丫头你怎么现在才来,再不来宗主可发火了.\n");
 else
 command("say 你小子现在才到,看呆会宗主不剥了你皮.\n");
}
  return;
}
