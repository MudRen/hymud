// created 11/22/1997 by snowcat
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("����", ({"gong zhu", "zhu", "princess"}));
  set("title", "���ù�");
  set("gender", "Ů��");
  set("age", 30);
  set("attitude", "peaceful");
  set("combat_exp", 30000);
  set_skill("dodge", 10);
  set_skill("parry", 10);
  set_skill("force", 10);
  set_skill("spells", 10);
  set_skill("unarmed", 10);


  set("max_jing", 300);
  set("max_qi", 300);
  set("max_jing", 300);
  set("neili", 300);
  set("max_neili", 300);
  set("neili", 300);
  set("max_neili", 300);
  set("force_factor", 30);
  set("mana_factor", 30);
  setup();
  initlvl((860+random(860)),2);
  carry_object("/d/obj/cloth/linen")->wear();
}

void init ()
{
  call_out ("check_king",4);
}

void check_king ()
{
  object me = this_object();
  object king = present ("guo wang",environment(me));

  if (! king)
    return;

  if (! king->query("my_saver"))
    return;

  if (me->query("seen_king"))
    return;

  me->set("seen_king",1);
  call_out ("reset_seen_king",600); 
  message_vision ("$N����$n����æ�˹�ȥ���������\n",me,king);
  message_vision ("$N��ʱ�����ݺᣬ����ס�е����Ҷ��ܿ����ۣ�\n",king);
  call_out ("crying",5,me,king); 
}

void crying (object me, object king)
{
  message_vision ("\n��Ů���޳�һ�ţ�\n",king);
  message_vision ("�������е��˶������˱�ϲ�����ᡣ\n",king);
  call_out ("finishing",5,me,king); 
}

void finishing (object me, object king)
{
  object who = king->query("my_saver");
  object junji = present ("jun ji",environment(me));
  object taijian1 = present ("tai jian 1",environment(me));
  object taijian2 = present ("tai jian 2",environment(me));

//added by tree,2001-7-24
   object fangzhang = present ("fang zhang",environment(me));
  if (! who)
    return;

  if (junji)
    destruct (junji);
  if (taijian1)
    destruct (taijian1);
  if (taijian2)
    destruct (taijian2);
  if (fangzhang)
   destruct (fangzhang);
  if (king)
  {
    king->announce_success (who);
    message_vision ("$N��$n��л��\n",king,who);
    destruct (king);
  }
  if (me)
  {
    message_vision ("$N��$n��л��\n",me,who);
    message_vision ("һ����������ȥ��\n",who);
    destruct (me);
  }
}

void reset_seen_king ()
{
  set("seen_king",0);
}
