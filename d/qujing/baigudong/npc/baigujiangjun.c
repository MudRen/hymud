// writted by smile 12/09/1998
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("�׹ǽ���", ({"baigu jiangjun", "jiangjun"}));
  set("gender", "����");
  set("age", 55);
  set("per",10);
  set("attitude", "friendly");
  set("combat_exp", 400000);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("sword", 110);
 
  set("eff_dx",-50000);
  set("nkgain",400);
  set("max_jing", 800);
  set("max_qi", 800);
  set("max_jing", 800);
  set("neili", 700);
  set("max_neili", 700);
  set("neili", 980);
  set("max_neili", 980);
  set("force_factor", 60);
  set("mana_factor", 60);


  setup();
    initlvl((350+random(350)),5);
  carry_object("/d/qujing/baigudong/obj/gusword")->wield();
  carry_object("/d/obj/armor/gujia")->wear();
}

int accept_fight (object ob)
{
  
  kill_ob (ob);
  return 1;
}
void init ()
{
  object ob = this_player();
  object me = this_object();
  call_out("greeting", 1, ob);
} 

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  if (ob && interactive(ob))
  {
    if (! ob->query_temp("people_kill"))
     {
      command("consider "+ob->query("id"));
      message_vision ("$N�����þ�û�����⣬�벻���������������ˣ�\n",this_object());
      command("spank");
     }
     this_object()->kill_ob(ob);
    ob->set_temp("people_kill",1);
  }
}
