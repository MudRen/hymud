
#include <ansi.h>
inherit NPC;

void create()
{
  string name, id;

  set_name("金甲卫士", ({ "jinjia weishi", "guard", "weishi" }) );
  set("gender", "男性" );
  set("long", "

一名威风凛凛的天将，奉王母之命，看守瑶池。
尽忠职守，不会将任何没有请柬的人私放入内。
");
  set("age", 35+random(10));
  set("attitude", "peaceful");
  set("str", 80);
  set("int", 25);
  set("per",21);
  set("combat_exp",100000);
  set("daoxing",100000);
  set("neili",500);
  set("max_neili",500);
  set("force_factor", 50);
  set("max_qi", 900);
  set("max_jing", 600);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 20);
	set_skill("force", 250);
	set_skill("club", 300);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);
	set_skill("hunyuan-yiqi", 200);
	set_skill("weituo-chu", 300);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	map_skill("club",  "weituo-chu");
	map_skill("parry", "weituo-chu");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 199);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 390);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 200);
	set_skill("zui-gun", 200);
	set_skill("buddhism", 200);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "weituo-chu");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                            }) );
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);
  setup();
 	carry_object("/clone/weapon/club")->wield();
	carry_object(__DIR__"xianpao")->wear();
}

void unconcious() {die();}

int accept_object(object me, object ob)
{

   if ((string)ob->query("id")!="invitation letter") return 0;
   call_out("verify",1,me);  
   return 1;
}      

void verify(object me) {

  if (me->name()!="赤脚大仙") {
    tell_object(me,"你一抬头，发现金甲卫士正把一道锐利的目光向你投来。\n");
    command("hmm");
    command("say 这张请柬明明是给赤脚大仙的，怎么到了你的手里？！");
    message_vision(CYN"$N吓得魂不附体，颤身说道：“我捡的，我地上捡的，我。。”\n"+
        "话没说完，就一溜烟地躲进了角落。\n"NOR,me);
    return;
  }

  command("say 原来是赤脚大仙驾到。");
  command("bow daxian");
  command("say 快里边请。。。");
  me->set_temp("yaochi_pass",2);
}
