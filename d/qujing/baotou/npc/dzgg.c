// rewritten by snowcat on 4.12.1997

inherit NPC;
#include "/d/migong/romnpc2.c"
int move_player();

void create()
{
  set_name("����Ź�", ({"diaozuan guguai", "guguai", "guai"}));
  set("gender", "����");
  set("age", 20);
  set("attitude", "friendly");
  set("combat_exp", 150000);
  set("combat_exp", 200000);

  set("per", 25);
  set_skill("dodge", 60);
  set("max_jing",600);
  set("max_qi",600);
  set("max_jing",600);
  set("neili",800);
  set("max_neili",800);
  set("max_neili",800);
  set("force_factor",25);
  set_skill("unarmed",60);
  set_skill("parry",60);
  set_skill("dodge",60);
  setup();
initlvl((600+random(600)),56);
  set("inquiry", ([
       "here": "����Ǳ�ͷɽ�������ǻ��ڶ�Ҳ��\n",
       "��ͷɽ": "��ͷɽ��������ǻ��ڶ���\n",
       "���ڶ�": (: move_player :),
       "dong": (: move_player :),
       "name": "����Ź֡�\n",
      ]));
  carry_object("/d/qujing/baotou/obj/cloth1")->wear();
  carry_object("/d/qujing/baotou/obj/weapon1")->wield();

}

int move_player()
{
  object me = this_object();
  object who = this_player();

  message_vision ("$N����$nһ�ۡ�\n",me,who);
  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$Nҡҡͷ�����в�����ȥ����ȥ���á�\n",me);
    return 1;
  }

 
  message_vision ("$N˵��$n�����Ϳ��Ҳ���ֵ���һ�žͰ����߽����\n",me,who);
  message_vision ("˵��$N����һ�ţ�$n˳������һԾ��\n",me,who);
  who->move("/d/qujing/baotou/dongwai");
  message_vision ("����һ���ȷ紵����$N�е�һ��ͻ��������ͷ�Ρ�\n",who);
  who->set("neili",0);
  return 1;
}
