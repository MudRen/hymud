//Cracked by Roath
 

inherit NPC;
#include <ansi.h>
#include "/d/migong/romnpc2.c"
void create()
{
          set_name("�Ʒ��", ({"huangfeng guai","yao guai","guai"}));
                    set("long","һ��������ɵ����֣�����ִһ�����ɲ档\n");

          set("gender", "����");
          set("age", 50);
          set("combat_exp", 800000);
          set("combat_exp", 800000);
          set("per", 20);
          set("str", 30);
          set("max_qi", 3000);
          set("max_jing", 1000);
          set("neili", 3000);
          set("max_neili", 1500);
          set("force_factor", 80);
          set("max_neili", 1000);
          set("neili", 1600);

          set_skill("unarmed", 120);
          set_skill("dodge", 120);
          set_skill("force", 120);
          set_skill("parry", 120);

          setup();
          add_money("gold", 1);
          initlvl((350+random(200)),7);
         carry_object("/d/qujing/huangfeng/obj/fork")->wield();
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
   remove_call_out("checking");
  call_out("checking",3,this_object());
}
void destruct_me (object me)
{
  destruct (me);
}

void checking(object me)
{
  object obj;
  string dan= "dingfeng dan";
  object ob = query_temp("my_killer");
  if (!objectp(obj = present(dan, ob)))
  {
  object where = environment(me);
  object room = load_object("/d/city/guangchang");
  message_vision(HIY"ֻ���Ʒ�ִ���һ�ģ�������������硣\n"NOR,ob);
  message_vision(HIY"ֻ��$N�����еķ�ɳһ����������ա�\n"NOR,ob);
  
  ob->move(room);
  }
  return ;
}
void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");

  if (ob)
  {
    ob->set_temp("obstacle/hfg_killed",1);
    call_out ("lingji_appearing",1,ob);
  }
  message_vision(HIM"ֻ���Ʒ��ˤ���ڵأ����˱��Ρ�ԭ����ֻ��ë����\n"NOR,ob);
  message_vision(HIM"���ϴ����鼪���������������󣡻������һ�ȥ������\n"NOR,ob);
         call_out ("destruct_me",3,me);
}
void lingji_appearing (object who)
{
  object lingji = new ("/d/qujing/huangfeng/npc/lingji");

  lingji->announce_success (who);
  destruct (lingji); 
}
void unconcious ()
{
  die ();
}
