//Cracked by Roath

inherit NPC;
#include "/d/migong/romnpc2.c"
#include <ansi.h>

void create()
{
          set_name("����", ({"yao guai","yao","guai"}));
          set("long","�����Ǿ����󽫣�����һ�ʧ�ִ��Ʋ���յ�����ᵽ�½硣\n");
          set("gender", "����");
          set("age", 23);
          set("per",30);        
          set("combat_exp", 1500000);
	  set("combat_exp",9500000);
          set("per", 30);
          set("str", 30);
          set("max_qi", 1200);
          set("qi",1200);
          set("force_factor",20);
          set("max_jing", 800);
          set("env/wimpy",70);
          set("jing",800);
          set("neili", 4000);
          set("max_neili", 2000);
          set("max_neili", 1000);
          set("neili", 2000);
          set_skill("unarmed", 140);
          set_skill("dodge", 140);
          set_skill("force", 140);
          set_skill("parry", 140);


         setup();
         initlvl((300+random(250)),9);
        carry_object("/d/qujing/liusha/obj/staff")->wield();
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
  set_leader(ob);
  ::kill_ob(ob);
  call_out ("checking",3,this_object());
  call_out ("back",5,this_object());

}
void checking(object me)
{
  object ob=query_temp("my_killer");
  object where = environment(me);
  object room = load_object("/d/qujing/liusha/riverside");
  if( present(ob,where) )
  {
  message_vision (HIY"\n���Ȼ�о���һ�����ƣ�����������ף�\n",me);
  message_vision ("���$Nͬʱ��ˮ�������˳�����\n"NOR,me);
  me->move(room);
  ob->move(room);
  }
  return;
}

void back(object me)
{
        object ob = query_temp("my_killer");
        object where = environment(me);
        object room = load_object("/d/qujing/liusha/cave");
        if( me->is_fighting() )
        call_out("back",1,me);
        if( ! where || where->query("short") != "����" )
                {
        message_vision(HIR"$N���һ�����б��£�����ˮ���¼���\n",me);
        message_vision("ֻ��$N���һ�У�����ˮ�С�\n"NOR,me);
        me->move(room);
        call_out("checking",2,me);
                }
        return;        
}
void destruct_me (object me)
{
  destruct (me);
}

void die()
{
  object here;        
  object ob = query_temp("my_killer");
  object me = this_player();
  object yudi=new(__DIR__"yudi");

	if (ob)
  	{
	ob->set_temp("sha_killed","yes");  
	message_vision ("\n��Ȼ���ϴ�����۵�������\n",me);
  	message_vision ("\n�㷢��$N������ʧ����Ӱ���٣�\n",me);
	here=environment(ob);
	yudi->move(here);
  	}
  destruct(this_object());
 return;
}
void unconcious ()
{
  die ();
}
