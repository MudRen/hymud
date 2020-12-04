// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("��Ǵ���", ({ "jinjiao dawang", "jinjiao", "dawang", "wang" }));
  set("title", "������");   
  set("long", "һλ��̬��Ȼ��������������\n");
  set("gender", "����");
  set("age", 56);
  set("attitude", "heroism");
  set("per", 30);
  set("max_qi", 1800);
  set("max_jing", 1800);
  set("max_jing", 1800);
  set("neili", 1200);
  set("max_neili", 1200);
  set("force_factor", 80);
  set("max_neili", 1200);
  set("neili", 1200);
  set("mana_factor", 80);
  set("combat_exp", 950000);
  set("combat_exp", 18000000);

 
  setup();
  initlvl((320+random(330)),62);
  carry_object("/d/obj/cloth/shoupipifeng")->wear();
  if (clonep())
  {
    object ob = new("/d/qujing/pingding/obj/hulureal");
    if (!ob) ob = new("/d/qujing/pingding/obj/hulufake");
    ob->move(this_object());
  }
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object fabao = present ("fabao",me);
  object taishang = new ("/d/qujing/pingding/npc/taishang");
  if (ob)
  {
    ob->set_temp("obstacle/pingding_jinjiao_killed",1);
  taishang->announce_success (ob);
  destruct (taishang); 
  }
  message_vision ("\n$N�޿��κε���������ԭ����̫���Ͼ��Ľ��ͯ�ӡ�\n",me);
  message_vision ("\n���ͯ�Ӿ��˸�����ʱ���ѵ���ȥ��̫���Ͼ�Ҳ��\n",me);
  message_vision ("���ͯ�����ⱼȥ",me);
  if (fabao)
  {
     message_vision ("������һֻ$n��\n",me,fabao);
     fabao->move(environment(me));
  }
  else
    message_vision ("��\n",me);
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

�
