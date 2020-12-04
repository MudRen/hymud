//Cracked by Roath

inherit NPC;
#include <ansi.h>
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("观音菩萨", ({ "guanyin pusa", "guanyin", "pusa" }));
	set("title", "救苦救难大慈大悲");
	set("long", @LONG
理圆四德，智满金身。眉如小月，眼似双星。兰心欣紫竹，
蕙性爱得藤。她就是落伽山上慈悲主，潮音洞里活观音。
LONG);
	set("gender", "女性");
	set("age", 35);
	set("attitude", "peaceful");
	set("rank_info/self", "贫僧");
	set("rank_info/respect", "菩萨娘娘");
	set("class", "bonze");
        	set("str",24);
	set("per",100);//means no rong-mao description.
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("max_jing", 5000);
	set("neili", 4000);
	set("max_neili", 2000);
	set("force_factor", 145);
	set("max_neili", 3000);
	set("neili", 6000);
	set("mana_factor", 150);
	set("combat_exp", 20000000);
	set("combat_exp", 10000000);

	set_skill("literate", 150);


	setup();
initlvl((500+random(500)),1);
	carry_object("/d/qujing/nanhai/obj/jiasha")->wear();
	carry_object("/d/qujing/nanhai/obj/nine-ring")->wield();
}

void announce_success (object who)
{
  
  int i;

  if(!who) return;

  if (who->query("combat_exp",1) < 1000000)
    return;
  if (who->query("obstacle/jz") == "done")
    return;
  if (! who->query_temp("obstacle/jz_libiao_killed"))
    return;
  if (! who->query_temp("obstacle/jz_liuhong_killed"))
    return;
//  if ( who->query("dntg/laojunlu") != "done")
//    return;

  	i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/jz","done");
  who->add("combat_exp",i+6800);
   who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"杀死刘洪等人，救出光蕊。");
message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+who->query("name")+"闯过西行取经[1;37m第一关！\n"NOR,users());
  tell_object (who,"你赢得了"+chinese_number(i+6800)+"点经验"+
               chinese_number(i*8)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
  who->save();
}
