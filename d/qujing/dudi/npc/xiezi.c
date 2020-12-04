// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("Ы�Ӿ�", ({ "xiezi jing", "xiezi", "jing" }));
  set("title", "���ö�");   
  set("long", "һλ��ɫ���˵�Ů������\n");
  set("gender", "Ů��");
  set("age", 26);
  set("attitude", "heroism");
  set("per", 29);
  set("max_qi", 150000);
  set("max_jing", 150000);
  set("max_jing", 150000);
  set("neili", 120000);
  set("max_neili", 120000);
  set("force_factor", 30);
  set("max_neili", 600);
  set("neili", 600);
  set("mana_factor", 30);
  set("combat_exp", 450000);
  set("combat_exp", 35000000);


  map_skill("force", "moonforce");
  setup();
  initlvl((450+random(450)),37);
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/dudi/obj/cha")->wield();
}

int test_player (object who)
{
  string *names;
  string name;
  int len;

  if (! who)
    return 0;


  return 1;    
}

void disappear_me (object me)
{
  message_vision ("\n$N����һ�����ӵ���Ӱ���٣�\n",me);
  destruct (me);
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
object maoxiu = new ("/d/qujing/dudi/npc/maoxiu");
  if (! ob)
  {
    disappear_me(me);
    return;
  }

  if (! test_player(ob))
  {
    disappear_me(me);
    return;
  }

  ob->set_temp("obstacle/dudi_killed",1);
  maoxiu->announce_success (ob);
  destruct (maoxiu); 
  message_vision ("\n$N��������ſ�ڵ��ϣ�ԭ����һֻ���ô�С�Ķ�Ы�ӡ�\n",me);
  message_vision ("\n������������ǹٵ�Ӱ�ӣ���Ы��ʰ����ƶ�ȥ��\n",me);
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
  call_out ("disappearing",1,me,ob);  
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void disappearing (object me, object ob)
{
  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;

  if ((! test_player(ob)) &&
       (me->query("qi") < (me->query("max_qi")/4) ||
        me->query("jing") < (me->query("max_jing")/4)))
  {
    disappear_me(me);
  }
  call_out ("discovering",1,me,ob);  
}

void hurting (object me, object ob)
{
  string *msgs = ({
    "$N��ȹ��һ�ƣ�̧�𶾴���$nһ����\n",
    "$Nһת��һ������׮��$n��ȥ��\n",
    "$N������$n��ͷ��һ����\n",
  });
  string *strs = ({
    "( $N���һ������ʹ�� )\n",
    "( $N���������ͷ�̲�ס�ҽ�һ���� )\n",
    "( $N��ͷ����������һ����������Ӹ�� )\n",
  });
  int damage;

  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;
 
  message_vision ("\n"+msgs[random(sizeof(msgs))],me,ob);
  
  if (! test_player(ob))
  {
    message_vision (strs[random(sizeof(strs))],ob);
    damage = ob->query("max_qi")/(7+random(3));
    ob->add("qi",-damage); 
    ob->add("eff_qi",-damage); 
    ob->add("jing",-damage); 
    ob->add("eff_jing",-damage); 
  }
  else
  {
    message_vision ("ֻ��$N����һ�����У�"+
                    "$n��ʱ���ҵط���ȹ��������׮��\n",ob,me);
  }
  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}
�