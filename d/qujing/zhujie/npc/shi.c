// created 11/20/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("九头狮", ({ "jiutou shi", "shi" }));
  set("title", "九灵元圣");   
  set("long", "一位老妖怪，长着九个狮子头。\n");
  set("gender", "男性");
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
  message_vision ("\n$N扑倒在地，现身为一头九头狮座。\n",me);
  message_vision ("\n半空中传来救苦天尊的怒喝：元圣儿，回府！\n",me);
  message_vision ("九头狮随着一阵彩云而去。\n",me);
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
    message_vision ("\n$N摇晃出一只狮子头，将自己伤处一舔！\n",me);
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
    "$N将一只狮子头伸长，一口把$n含在嘴里！\n",
    "$N伸出一只狮头，将$n凌空衔起！\n",
    "$N的狮子头一摆，张开血盆大口将$n咬起！\n",
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

    message_vision ("但见$N手起刀落，"+
                    "$n惨嚎一声，一只狮头落地！\n",ob,me);
    head->move(environment(me));
    me->add("heads",-1);
    me->set("long", "一位老妖怪，还剩下"+chinese_number(heads-1)+"个狮子头。");
  }
  remove_call_out ("hurting");  
  call_out ("hurting",random(20)+20,me,ob);  
}
�
