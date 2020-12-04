// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/huxianfeng.c

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("虎先锋", ({"hu xianfeng", "hu", "xianfeng"}));
	set("gender", "男性" );
	set("age", 43);
	set("per", 112);//no rongmao description.
	set("str", 50);
		set("long", "黄风大王部下的前路先锋，是黄风大王最得力的助手。\n武艺高强，做事干净利落，又善于拍马屁，\n所以这黄风山上他是一人之下万人之上。\n");

	set("class", "yaomo");
	set("combat_exp", 800000);
	set("attitude", "peaceful");
	set_skill("unarmed", 130);


	set("max_qi", 1200);
	set("max_jing", 600);
	set("neili", 1600);
	set("max_neili", 800);
	set("neili", 800);
	set("max_neili", 400);	
	set("force_factor", 60);
	set("mana_factor", 20);

        set("eff_dx", -200000);
        

	setup();
	initlvl((200+random(200)),2);
	carry_object("/d/qujing/huangfeng/obj/hupi")->wear();
}
void die()
{
  object me = this_object();
  object where = environment(me);
  object ob = new ("/d/qujing/huangfeng/obj/hupi");

  message_vision ("$N惨叫声中翻身倒地，轻烟过处，只留下一张老虎皮。\n",me);
  ob->move(where);
  destruct(me);
}
