// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("��ü�Ϸ�", ({ "huangmei laofo", "huangmei", "laofo", "fo" }));
  set("title", "С������");   
  set("long", "һλ���ޱ���ȴ�־���������Ϸ�\n");
  set("gender", "����");
  set("age", 80);
  set("attitude", "heroism");
  set("per", 30);
  set("max_qi", 260000);
  set("max_jing", 260000);
  set("max_jing", 260000);
  set("neili", 360000);
  set("max_neili", 360000);
  set("force_factor", 75);
  set("max_neili", 331600);
  set("neili", 331600);
  set("mana_factor", 75);
  set("combat_exp", 1450000);
  set("combat_exp", 48000000);

  setup();
  initlvl((600+random(600)),48);
  carry_object("/d/obj/cloth/jia_sha")->wear();
  carry_object("/d/qujing/xiaoxitian/obj/mace")->wield();
 carry_object("/d/qujing/xiaoxitian/obj/baoreal");

}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object mile = new ("/d/qujing/xiaoxitian/npc/mile");
  object fabao = present ("fabao",me);

  if (ob)
  {
    ob->set_temp("obstacle/xiaoxitian_killed",1);
  mile->announce_success (ob);
  destruct (mile); 
  }
  message_vision ("\n������֣����շ������˽�����\n",me);
  message_vision ("\n$N��æ���Ź���������ȴ������һ��üСͯ��\n",me);
  message_vision ("���շ������Ż�üСͯ���˳�ȥ",me);
  if (fabao)
  {
     message_vision ("������һֻ$n��\n",me,fabao);
     fabao->move(environment(me));
  }
  else
    message_vision ("��\n",me);
::die();
}

void mile_appearing (object who)
{
  


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
