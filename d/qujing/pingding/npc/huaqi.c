// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("�����ߴ���", ({ "huaqi dawang", "huaqi", "dawang", "wang" }));
  set("title", "ѹ����");   
  set("long", "һλŤ�����ε�ѹ�������������������ط���������\n");
  set("gender", "����");
  set("age", 64);
  set("attitude", "heroism");
  set("per", 30);
  set("max_qi", 1400);
  set("max_jing", 1400);
  set("max_jing", 1400);
  set("neili", 1000);
  set("max_neili", 1000);
  set("force_factor", 60);
  set("max_neili", 1000);
  set("neili", 1000);
  set("mana_factor", 60);
  set("combat_exp", 650000);
  set("combat_exp", 18000000);

 
  setup();
  initlvl((310+random(310)),59);
  carry_object("/d/obj/cloth/shoupipifeng")->wear();
 
    carry_object("/d/qujing/pingding/obj/shengreal");
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
   object taishang = new ("/d/qujing/pingding/npc/taishang");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/pingding_huaqi_killed",1);
  taishang->announce_success (ob);
  destruct (taishang); 
  }
  message_vision ("\n$N�����ڵ�����������һֻ���꾫��\n",me);
  message_vision ("���꾫���ˡ�\n",me);
::die();
}



void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (fabao)
    fabao->ji_ob (ob);

  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}

