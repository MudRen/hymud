
inherit NPC;

void create()
{
  set_name("����", ({"wang hou", "hou", "queen"}));
  set ("long", "�ڼ������������ճ�ü��������˼���ء�\n");
  set("title", "�ڼ���");
  set("gender", "Ů��");
  set("age", 40);
  set("combat_exp", 100000);
  set("combat_exp", 50000);

  set_skill("blade", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);
  set_skill("force", 20);
  set("max_jing", 5000);
  set("max_qi", 5000);
  set("max_neili", 5000);
  set("neili", 100);
  set("force_factor", 4);
  setup();
 
  carry_object("/d/obj/cloth/gongpao")->wear();
}

int accept_object (object who, object ob)
{
  object me = this_object();

  if (ob->query("id") != "yu gui")
    return 0;

  remove_call_out ("telling");
  call_out ("telling",1,me,who,ob);
  message_vision ("$N����$nһ������ʱ��ɫ��������\n",me,ob);
  command ("shake");
  who->set_temp("obstacle/wuji_queen",1);
  return 1;
}

void telling (object me, object who, object ob)
{
  object yugui = present ("yu gui",me);
  
  if (! yugui)
  {
    yugui = new ("/d/qujing/wuji/obj/jade");       
    yugui->move(me);
  }
  message_vision ("�����$N˵������ȥ��̫�Ӱա�\n",who);
  message_vision ("����ѽ������绹��$N��\n",who);
  yugui->move(who);
}
