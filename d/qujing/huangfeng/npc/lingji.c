//Cracked by Roath
 
inherit NPC;
#include "/d/migong/romnpc2.c"
#include <ansi.h>
void create()
{
   set_name("灵吉菩萨", ({ "lingji pusa", "ling ji", "pusa" }));
   set("long","一个慈祥的灵山菩萨。");
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
   set("combat_exp", 2000000);
   set_skill("literate", 150);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
 

   setup();
   initlvl((300+random(200)),8);
   carry_object("/d/qujing/nanhai/obj/jiasha")->wear();
   carry_object("/d/qujing/nanhai/obj/nine-ring")->wield();
}

void announce_success (object who)
{
  int i;
  object me = this_object(); 
  
  if( ! who->query_temp("obstacle/hfg_killed"))
     return;
  if (who->query("obstacle/yz") != "done")
    return;  
  if( who->query("combat_exp") < 10000)
     return;
  if( who->query("obstacle/hfg") == "done")
    return;

  i = random(500);
  who->add("obstacle/number",1);
  who->set("obstacle/hfg","done");
    who->add("potential",i*7);
  who->add("mpgx",10);
         who->add("combat_exp",i+2000);
me->command("chat "+who->query("name")+"黄风山黄风岭收降黄风怪！");
  message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+who->query("name")+"闯过西行取经[1;37m第六关！\n"NOR,users());
  tell_object (who,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}
