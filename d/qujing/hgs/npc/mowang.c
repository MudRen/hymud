// sgzl

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("混世魔王", ({ "hunshi mowang", "mowang"}) );
  set("gender", "男性" );
       set("long",
                "只见这魔王：\n
　　头戴乌金盔，映日光明；身挂皂罗袍，迎风飘荡。
    下穿着黑铁甲，紧勒皮条；足踏着花褶靴，雄如上将。
    腰广十围，身高三丈，手执一口刀，锋刃多明亮。
    称为混世魔，磊落凶模样。\n");
  set("age", 30);
  set("str", 30);
  set("per", 30);
  set("int", 30);
  set("attitude", "killer");
  
  set("combat_exp", 150000);
  set("daoxing", 100000);



 

  setup();
initlvl((600+random(600)),61);
  carry_object("/d/obj/armor/tongjia.c")->wear();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/obj/weapon/blade/yanblade.c")->wield();
}

void init()
{
  object ob=this_player();

  ::init();
     remove_call_out("greeting");
     call_out("greeting", 1, ob);
}

void greeting(object ob)
{
  object me=this_object();
  message_vision("$N喝道：这地盘老子占了，来找死嘛！\n",me);
  command("kill " + ob->query("id"));
}


int accept_fight (object ob)
{
  
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}


void die()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  object ma;
  object panzi;

  if (ob)
  {
  message_vision ("\n$N惨叫一声，被砍为两段。\n",me);
  ma = new (__DIR__"ma");
  message_vision ("\n猴子头领马元帅领着几只猴子跑了过来，看到$N被斩，高兴的跳了起来。\n",me);
  if(ob->query("dntg/huaguo")!="done")  
    {
    ma->announce_success (ob);
    panzi = new ("/d/qujing/hgs/obj/shipan");
    panzi->move(ob);
    }
  message_vision ("\n马元帅带着众猴子七手八脚的把$N的尸体拖了出去。\n",me);
  destruct (ma);
  }
  destruct(me);
}

��
