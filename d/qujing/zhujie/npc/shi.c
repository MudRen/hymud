// created 11/20/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("��ͷʨ", ({ "jiutou shi", "shi" }));
  set("title", "����Ԫʥ");   
  set("long", "һλ�����֣����žŸ�ʨ��ͷ��\n");
  set("gender", "����");
  set("age", 70);
  set("attitude", "heroism");
  set("per", 29);
  set("max_qi", 441500);
  set("max_jing", 441500);
  set("max_jing", 441500);
  set("neili", 441200);
  set("max_neili", 441200);
  set("force_factor", 100);
  set("max_neili", 44600);
  set("neili", 44600);
  set("mana_factor", 80);
  set("combat_exp", 750000);
  set("combat_exp", 68000000);

  
  set("heads", 9);
  setup();
    initlvl((750+random(760)),48);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object prince = new ("/d/qujing/yuhua/npc/prince");
  if (ob)
  {
    ob->set_temp("obstacle/yuhua_killed",1);
  prince->announce_success (ob);
  destruct (prince); 
  }
  message_vision ("\n$N�˵��ڵأ�����Ϊһͷ��ͷʨ����\n",me);
  message_vision ("\n����д����ȿ������ŭ�ȣ�Ԫʥ�����ظ���\n",me);
  message_vision ("��ͷʨ����һ����ƶ�ȥ��\n",me);
::die();
}



void destruct_me(object me)
{
  destruct(me);
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
  call_out ("recovering",1,me,ob);  
  call_out ("hurting",random(20)+20,me,ob);  
  ::kill_ob(ob);
}

void recovering (object me, object ob)
{
  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;

  if (me->query("heads") > 0 &&
      (me->query("qi") < (me->query("max_qi")*3/4) ||
       me->query("jing") < (me->query("max_jing")*3/4)))
  {
    message_vision ("\n$Nҡ�γ�һֻʨ��ͷ�����Լ��˴�һ��\n",me);
    me->set("jing",me->query("max_jing"));
    me->set("qi",me->query("max_qi"));
    me->set("jing",me->query("max_jing"));
    me->set("eff_jing",me->query("max_jing"));
    me->set("eff_qi",me->query("max_qi"));
    me->set("eff_jing",me->query("max_jing"));
  }
  call_out ("recovering",1,me,ob);  
}

void hurting (object me, object ob)
{
  string *msgs = ({
    "$N��һֻʨ��ͷ�쳤��һ�ڰ�$n�������\n",
    "$N���һֻʨͷ����$n�������\n",
    "$N��ʨ��ͷһ�ڣ��ſ�Ѫ���ڽ�$nҧ��\n",
  });
  object zhudao;
  int heads = me->query("heads");

  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;
  
  zhudao = present("taiyi zhu dao",ob);
  if (! zhudao ||
      zhudao != ob->query_temp("weapon"))
  {
    message_vision ("\n"+msgs[random(sizeof(msgs))],me,ob);
    ob->move("/d/qujing/zhujie/shi");
    ob->unconcious();
  }
  else if (heads>0)
  {
    object head = new("/d/qujing/zhujie/obj/head");

    message_vision ("����$N�����䣬"+
                    "$n�Һ�һ����һֻʨͷ��أ�\n",ob,me);
    head->move(environment(me));
    me->add("heads",-1);
    me->set("long", "һλ�����֣���ʣ��"+chinese_number(heads-1)+"��ʨ��ͷ��");
  }
  remove_call_out ("hurting");  
  call_out ("hurting",random(20)+20,me,ob);  
}
�
