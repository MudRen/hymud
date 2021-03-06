//Cracked by Roath

inherit NPC;
#include "/d/migong/romnpc2.c"
#include <ansi.h>
void create()
{
   set_name("揭谛", ({ "jie di"}));
   set("title", "观音侍者");
   set("long", @LONG
观音菩萨的侍者。
LONG);
   set("gender", "男性");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "贫僧");
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
   set("combat_exp", 2000000);
   set_skill("literate", 150);
  

   setup();
   initlvl((500+random(500)),1);
   carry_object("/d/qujing/nanhai/obj/sengpao")->wear();
   //carry_object("/d/qujing/nanhai/obj/budd_staff")->wield();

}

void announce_success (object who)
{
  int i;
  object horse=new("/d/qujing/yingjian/obj/horse");
  object here;
  object me = this_object();
  here=environment(who);

  if (who->query("combat_exp",1) < 1000000)
    return;
  if (who->query("obstacle/yj") == "done")
    return;
  if (! who->query_temp("obstacle/long_killed"))
    return;
  if (who->query("obstacle/sc") != "done")
    return;  
    
  i = random(900);
  message_vision (HIY"一片祥云过后，揭谛出现在你面前！\n",who);
  message_vision (HIY"\n只听揭谛怒斥一声敖闰龙王玉龙三太子还不拜过取经人！\n",who);
  message_vision (HIY"\n忽然白龙扑倒在地，变成了一匹白马。\n",who);
  horse->move(here);
  who->add("obstacle/number",1);
  who->set("obstacle/yj","done");
  who->add("combat_exp",i+8000);
  who->add("potential",i*8);
  who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"鹰愁涧降服白龙马！");
message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+who->query("name")+"闯过西行取经[1;37m第三关！\n"NOR,users());
        tell_object (who,"你赢得了"+chinese_number(i+8000)+"点经验"+
               chinese_number(i*8)+"点潜能"+
               "十点门派贡献 二点成长上限！\n");

	  command("wave");
	  who->save();
}
