//liuer-mihou.c weiqi...98/05/13

#include <ansi.h>
#define MAX_TRY 20
inherit NPC;
#include "/d/migong/romnpc2.c"
string ask_me();

void create()
{
	set_name("����⨺�", ({"liuer mihou", "liuer", "mihou"}));
	set("title", "��ͨ��");
	set("gender", "����" );
	set("age", 35);
	set("per", 14);
	set("str", 30);
	set("long", "����⨺����������Ԫ�������£�ѧ��һ��ñ��졣\n�������Ծ�����Ԫ���ɲ���ˣ��㿪ʼ������������\n��Ȼȥ��԰͵���˲ι�������ǹ���û���ŷ�������Ԫ���ɴ�ס��\nʹ�ӳ�����������ǽ��\n");
	set("class", "xian");
	set("combat_exp", 38500000);
	set("attitude", "peaceful");
	//create_family("��ׯ��", 2, "����");
	set("rank_info/respect", "��ү");


	set("max_qi", 200000);
	set("max_jing", 200000);
	set("neili", 200000);
	set("max_neili", 200000);
	set("neili", 200000);
	set("max_mana", 200000);	
	set("force_factor", 50);




	set("inquiry", ([
		"name": "�����ʥ�������Ҳ��\n",
		"here": "������\n",
		"�˲ι�": "��ү����ϲ���ľ����˲ι���\n",
		"ɱ��": "ɱ�ˣ�ֻҪ�����˲ι���ʲô����������\n",
		"�ؾ�": "�ؾ���ֻҪ�����˲ι���ʲô����������\n",
		"⨺��ּ�": "�ּǣ�ֻҪ�����˲ι���ʲô����������\n",
                "����"     : (: ask_me :),
                 "���"     : (: ask_me :),
	]) );

	setup();
initlvl((600+random(600)),24);	
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/hammer/tongchui")->wield();
}


string ask_me()
{
	this_player()->set_temp("liuer-mihou_ask","done");
	call_out("autokill",1,this_player(),this_object());
	return "�ٺ�";
}

void autokill (object me, object who)
{
  message_vision ("$n���һ��Ҫɱ��$N��\n",me,who);
  me->kill_ob(who);
  who->kill_ob(me);
}

void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);

  message_vision ("\n$N��ŭ���ĸ�������ð����Һ�ү��\n",this_player());

  set_temp("my_killer",ob);
  this_player()->kill_ob(me);
}

void unconcious()
{
  die ();
}





void die()
{
  object me = this_object();
  object ob = query_temp("my_killer");
    object guan = new (__DIR__"pusa");
  object xiangjiao;
  message_vision(HIY "\n����ͻȻ�Ӳ��Ƽ�����\n" NOR,me);
  message_vision(HIY "\n������$Nһ���֣������ͷ��\n" NOR,me);
  message_vision(HIY "$N��ѽһ������������\n\n" NOR,me);
  if ((ob) && (ob->query_temp("liuer-mihou_ask") == "done"))
  {
  	ob->set_temp("obstacle/liuer-mihou/liuer-mihou_killed",1);
	message_vision(HIC "����˵���������Ҵ��ߣ��㰲��ȡ��ȥ��! \n\n" NOR,me);
	
  guan->announce_success (ob);
  destruct (guan); 
  }
  ob->set_temp("liuer-mihou_ask","no");
        ::die();
}
