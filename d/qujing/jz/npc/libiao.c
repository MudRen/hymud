//Cracked by Roath

inherit NPC;
#include "/d/migong/romnpc2.c"
#include <ansi.h>

void create()
{
        set_name("���", ({"li biao","libiao","li"}));
        set("gender", "����");
        set("age", 38);
        set("title","����֪ү");
        set("long","һ����ǿ��׳�����ˣ���ô��Ҳ����֪ү��");
        set("attitude", "friendly");
        set("per", 10);
        set("str", 40);
        set("combat_exp",50000);
	set("combat_exp",5000000);		
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",40);
        set("max_qi",300);
        set("max_jing",300);
        set_skill("unarmed",80);
        set_skill("parry",80);
        set_skill("dodge",70);
        set_skill("changquan",80);
        map_skill("unarmed","changqaun");
        map_skill("parry","houquan");

        setup();
initlvl((100+random(100)),2);
}
void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object corpse;
object pusa;
  if (ob)
  {
    ob->set_temp("obstacle/jz_libiao_killed",1);
  pusa = new ("/d/qujing/jz/npc/pusa");

  pusa->announce_success (ob);
  destruct (pusa); 
  }
  message_vision ("������ˡ�\n",me);
::die();
}

void pusa_appearing (object who)
{
  object pusa = new ("/d/qujing/jz/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}

void unconcious ()
{
  die ();
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::kill_ob(ob);
}


