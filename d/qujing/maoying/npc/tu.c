// created 11/20/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
string *names = ({
  "���þ�",
  "���þ�",
  "���þ�",
  "���þ�",
  "���þ�",
  "��ë�þ�",
  "��ë�þ�",
  "��ë�þ�",
});

void jump_away ();

void create()
{
  set_name(names[random(sizeof(names))], ({ "tu jing", "tu", "jing" }));
  set("long", "һλ��ģ������Ů�ӡ�\n");
  set("gender", "Ů��");
  set("age", 20);
  set("attitude", "peaceful");
  set("per", 29);
  set("max_qi", 1800);
  set("max_jing", 1800);
  set("max_jing", 1800);
  set("neili", 1800);
  set("max_neili", 1800);
  //set("force_factor", 10);
  set("max_neili", 1100);
  set("neili", 1100);
  set("mana_factor", 80);
  set("combat_exp", 2540000);
  set("combat_exp", 68000000);


  set("chat_chance_combat", 2);
  set("chat_msg_combat", ({ (: jump_away :) }) );

  setup();
   initlvl((860+random(860)),2);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void jump_away ()
{
  string s;
  object room;
  object me = this_object();
  
  s = sprintf ("/d/qujing/maoying/shanpo%d.c",random(10)+1);
  room = load_object(s);
  message_vision ("ವ�һ����$N������ȥ����\n",me);
  me->move(room);
  if (present("tu jing 6",environment(me)))
    destruct (me);
  else
    message_vision ("$Nವ�һ�����˹�������\n",me);
}

void destruct_me(object me)
{
  destruct(me);
}

void unconcious ()
{
  die ();
}

void die ()
{
  object me = this_object();
  message_vision ("\n$N�����ڵأ���ԭΪһֻҰ�ã�����һ�ڡ�\n",me);
::die();
}
