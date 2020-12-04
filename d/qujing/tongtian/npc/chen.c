// rewritten by snowcat on 12.12.1997

inherit NPC;

void create()
{
  set_name("陈长老", ({"chen zhanglao", "chen", "zhanglao"}));
  set("gender", "男性");
  set("age", 70);
  set("attitude", "friendly");
  set("combat_exp", 50000);
  set("combat_exp", 50000);

  set("per", 35);
  set_skill("dodge", 30);
  set_skill("force", 30);
  set_skill("parry", 30);
  set("max_jing",6000);
  set("max_qi",6000);
  set("max_jing",6000);
  set("neili",5000);
  set("max_neili",5000);
  set("max_neili",5000);
  set("force_factor",5);
  setup();

  carry_object("/d/obj/cloth/choupao")->wear();

}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/tongtian") == "done")
    return;
  if (! who->query_temp("obstacle/tongtian_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/tongtian","done");
  who->add("combat_exp",i+22000);
  
     who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"通天河救童男女，水宅降鱼精！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(i+22000)+"点经验"+
               chinese_number(i*8)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
  who->save();
}
�
