//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("Ů��", ({"nu zi", "nu", "zi"}));
  set("gender", "Ů��");
  set("age", 18);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 30);
  set("attitude", "peaceful");
  set("combat_exp", 14000000);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
 
  set("max_jing", 700);
  set("max_qi", 700);
  set("max_jing", 700);
  set("neili", 800);
  set("max_neili", 800);
  set("neili", 800);
  set("max_neili", 800);
  set("force_factor", 60);
  set("mana_factor", 60);
  setup();
  initlvl((300+random(300)),5);
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/baoxiang/obj/mifan");
  carry_object("/d/qujing/baoxiang/obj/mianjin");
}

void init()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  ::init();
    remove_call_out ("greeting");
    call_out ("greeting",1,me,who);

}

void destruct_me (object me)
{
  destruct (me);
}

void greeting (object me, object who)
{
  if (me->is_fighting())
    return;

  if (! who ||
      environment(who) != environment(me))
    return;
  message_vision ("$N��$n˵����Ӵ���ʹӺ�����\n",me,who);

}

void unconcious()
{
  die();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object corpse,pusa;
pusa = new ("/d/qujing/sanda/npc/pusa");
  if (ob)
  {
    ob->set_temp("obstacle/sanda_nuzi_killed",1);
  pusa->announce_success (ob);
  destruct (pusa);
  }
  message_vision ("\n$N�����ڵ��ϣ����ˣ��ֳ�һ�Ѱ׹ǡ�\n",me);
::die();
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
 
