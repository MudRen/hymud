//Cracked by Roath
// snowcat 12 14 1997

inherit NPC;
#include "/d/migong/romnpc2.c"
#include <obstacle.h>

int do_tell ();

void create()
{
  set_name("��������", ({ "anuo zunzhe", "anuo", "zunzhe" }));
  set("title", "��ɽ");
  set("gender", "����");
  set("age", 1000);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_qi", 2000);
  set("max_jing", 2000);
  set("max_jing", 2000);
  set("neili", 2000);
  set("max_neili", 2000);
  set("force_factor", 80);
  set("max_neili", 2000);
  set("neili", 2000);
  set("mana_factor", 80);
  set("combat_exp", 1200000);
  set("combat_exp", 2500000);

  set("chat_chance_combat", 80);
  set("inquiry", ([
    "name" : "����Ҳ��",
    "here" : "��ɽҲ��",
    "��ɽ" : "�ҷ�����֮��ɽҲ��",
    "������" : "�ҷ�����֮������Ҳ��",
    "����" : (: do_tell :),
    "����" : (: do_tell :),
    "��ȡ�澭" : (: do_tell :),
    "ȡ��" : (: do_tell :),
    "�澭" : (: do_tell :),
    "��" : (: do_tell :),
  ]));


  setup();
    initlvl((1000+random(1000)),random(63));
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

void die()
{
  if (environment())
    message("sound", "\n"+this_object()->query("name")+"����һ��ͷ�����ޱߣ�\n\n", environment());

  set("eff_qi", 200000);
  set("eff_jing", 200000);
  set("eff_jing", 200000);
  set("qi", 200000);
  set("jing", 200000);
  set("jing", 200000);
  set("neili", 200000);
  set("neili", 200000);
}




int do_tell ()
{
  call_out ("telling",1,this_player());
  return 1;
}

int telling (object who)
{
  object me = this_object();

  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *strs = allocate (size);
  int nb = 0;
  int i;

  if (!objectp(who)) return 0;
  for (i = 0; i < size; i++)
  {
    strs[i] = "none";
  }

  for (i = 0; i < size; i++)
  {
    if (who->query("obstacle/"+names[i])=="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }

  if (nb == 0)
  {
    tell_object (who,me->query("name")+"�����㣺����δ������ȡ�澭��\n\n");
  }
  else
  {
    tell_object (who,me->query("name")+"�����㣺��������ȡ�澭�ѹ���"+
                     chinese_number(nb)+"�أ�\n");
    who->set("obstacle/number",nb);
    who->save();
    strs = (string *)sort_array (strs, 1);

    for (i = 0; i < nb; i++)
    {
      tell_object (who,"    "+strs[i]+"\n");
    }

    tell_object (who,"\n");
  }

  if (nb == size && who->query("obstacle/reward"))
  {
    who->set_temp("obstacle/lingshan_enter",1);
    if (environment(me)==environment(who) &&
        who->query("obstacle/reward") == 0)
      message_vision ("$N��$nһ�Ϲ����ҷ����룡\n",me,who);
  }

  return 1;
}

