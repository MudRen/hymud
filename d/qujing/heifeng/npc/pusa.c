//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// guanyin.c 观音菩萨
// By Dream Dec. 19, 1996
#include <ansi.h>
inherit NPC;

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
   set("combat_exp", 2000000);
   set_skill("literate", 150);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 150);
 

   //hehe, since guanyin was killed several times
   //let's use cast bighammer to protect her...weiqi:)
   create_family("南海普陀山", 1, "菩萨");

   setup();
   carry_object("/d/qujing/nanhai/obj/jiasha")->wear();

}
void announce_success (object who)
{
  int i;
  object me = this_object();

  if (who->query("combat_exp") < 10000)
    return;
  if( ! who->query_temp("fired") )
     return;
   if(who->query("obstacle/hf")  == "done")
    return; 
  if (! who->query_temp("obstacle/heixiong_killed"))
    return;
  if (who->query("obstacle/yj") != "done")
    return;  
    
  i = random(900);
  who->add("obstacle/number",1);
  who->set("obstacle/hf","done");
   who->add("combat_exp",i+9000);
   who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"黑风山收降黑熊怪！");
message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+who->query("name")+"闯过西行取经[1;37m第四关！\n"NOR,users());
        tell_object (who,"你赢得了"+chinese_number(i+9000)+"点经验"+
               chinese_number(i*8)+"点潜能"+
               "十点门派贡献 二点成长上限！\n");

	  command("wave");
	  who->save();
}

void die(object me)
{
        destruct(me);
}

