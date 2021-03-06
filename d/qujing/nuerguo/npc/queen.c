// created 4/5/1997 by snowcat
#include <ansi.h>
#define NAME "西梁披霜仙后"

inherit NPC;

void create()
{
  set_name(NAME, ({"xiliang xianhou", "queen"}));
  set("title", "晨曦女神");
  set("gender", "女性");
  set("age", 23);
  set("long", "西梁披霜仙后晨曦女神。\n");
  set("combat_exp", 1000000);
  set("combat_exp", 1000000);

  set_skill("snowsword", 100);
  set_skill("sword", 100);
  set_skill("unarmed", 100);
  set_skill("dodge", 120);
  set_skill("parry", 120);
  set_skill("dragonstep", 120);
  map_skill("dodge", "dragonstep");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("neili", 900);
  set("max_neili", 900);
  set("force_factor", 10);

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/obj/weapon/sword/feijian")->wield();
}

void init()
{
  ::init();
}

void announce_success(object who, string reason)
{//disabled announce and reward...
  int i;

  i = random(800);
if (who->query("obstacle/nuerguo") == "done")
return;
  who->add("obstacle/number",1);
  who->set("obstacle/nuerguo","done");
  who->add("combat_exp",i+28000);
     who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+reason+"，顺利闯过西行一关！");
  command("chat 西梁上下奔走相告！");
tell_object(who,"你赢得了"+chinese_number(i+28000)+"点经验"+
               chinese_number(i*8)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
  who->save();
  message_vision (HIY NAME+"在一阵白雾中徐徐消失。\n" NOR,who);
}

void refuse_player(object who)
{
  string name;
  name = who->name();
  message_vision (HIY NAME+"突然从白雾中闪出向$N摇摇头："+
                  "您已闯过西梁这一关了。快去西天取经吧。\n" NOR,who);
  message_vision (HIY "说罢"+NAME+"在一阵白雾中徐徐消失。\n" NOR,who);
}

void stop_access(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"从一团白雾中显出，告诉$N："+
                  "您尚未闯过西梁这一关，对不起。\n" NOR,who);
  message_vision (HIY "说罢白雾拥着"+NAME+"在空中慢慢地消失。\n" NOR,who);
}
�
