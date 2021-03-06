// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("蝎子精", ({ "xiezi jing", "xiezi", "jing" }));
  set("title", "琵琶洞");   
  set("long", "一位艳色迷人的女妖精。\n");
  set("gender", "女性");
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
  message_vision ("\n$N往外一闪，逃得无影无踪！\n",me);
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
  message_vision ("\n$N浑身酥软趴在地上，原来是一只琵琶大小的毒蝎子。\n",me);
  message_vision ("\n天空闪过昴宿星官的影子，将蝎子拾起驾云而去。\n",me);
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
    "$N将裙角一掀，抬起毒刺向$n一扎！\n",
    "$N一转身，一个倒马桩向$n刺去！\n",
    "$N跳起往$n的头上一扎！\n",
  });
  string *strs = ({
    "( $N大叫一声：好痛！ )\n",
    "( $N抱起肿起的头忍不住惨叫一声！ )\n",
    "( $N的头上立刻肿起一大块红红的脑门痈！ )\n",
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
    message_vision ("只见$N发出一声鸡叫，"+
                    "$n顿时慌乱地放下裙子收起倒马桩！\n",ob,me);
  }
  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}
�