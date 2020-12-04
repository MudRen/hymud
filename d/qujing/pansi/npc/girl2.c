// created 11/20/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("����", ({ "hua yu", "hua", "yu" }));
  set("title", "�߽���");   
  set("long", "һλ��ϼ���촽��ü���޵���Ů�ӡ�\n");
  set("gender", "Ů��");
  set("age", 20);
  set("attitude", "heroism");
  set("per", 30);
  set("max_qi", 500);
  set("max_jing", 500);
  set("max_jing", 500);
  set("neili", 500);
  set("max_neili", 500);
  set("force_factor", 60);
  set("max_neili", 500);
  set("neili", 500);
  set("mana_factor", 60);
  set("combat_exp", 350000);
  set("combat_exp", 53350000);

 
  setup();
  initlvl((500+random(500)),13);
  carry_object("/d/obj/cloth/nichang")->wear();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  if (ob && 
      ! ob->query_temp("obstacle/pansi_killed_"+me->query("name")))
  {
    ob->set_temp("obstacle/pansi_killed_"+me->query("name"),1);
    ob->add_temp("obstacle/pansi_killed",1);
  }
  message_vision ("\n$N����һ������ͷ����֩�뾫��ԭ�Ρ�\n",me);
  me->set_name("֩�뾫", ({"zhizhu jing", "zhizhu", "jing"}));
  ::die();
}

void unconcious ()
{
  die ();
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
  string *msgs = ({
    "$N����һ��¶����Ƥ��һ�ɴִֵİ�˿�罫������$nһ����\n",
    "$N�ǿ��·�����һֻͦ���ɹɰ�˿����$n��\n",
    "$N�����½ǣ������������һ�ɴְ�˿��$n��ȥ��\n",
  });
  string *strs = ({
    "( $N��ʱһ���ĵأ�ɲ�Ǽ�ˤ�����ذ��� )\n",
    "( $N����������ڵ��ϣ���ҡ�������������� )\n",
    "( $N�Ļ����̣������ŵ����ڵ��ϣ� )\n",
  });
  int damage;

  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;
 
  message_vision ("\n"+msgs[random(sizeof(msgs))],me,ob);
  message_vision (strs[random(sizeof(strs))],ob);
  damage = ob->query("max_qi")/(8+random(4));
  ob->add("qi",-damage); 
  ob->add("jing",-damage); 

  call_out ("hurting",random(10)+10,me,ob);  
}
