//Cracked by Roath
inherit NPC;

void create()
{
set_name("�쾦���", ({"bing chan", "hama"}));
set("race", "Ұ��");
set("age", 33);

set("long", @LONG
һֻ����ܣ�ͨ��ѩ�ף�����ȴѪҲ��죬ģ�����ǿɰ���ȴҲ�����к�����֮����
LONG);

set("attitude", "aggressive");
set("class", "yaomo");
set("combat_exp", (random(5)*100000+50000));
set("daoxing", (random(5)*100000+50000));
set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
set("verbs", ({ "bite"}));

set("kee", 800);
set("max_kee", 800);
set("sen", 1200);
set("max_sen", 800);
set("force", 2000);
set("max_force", 1800);
set("mana", 1000);
set("max_mana", 500);
set("force_factor", 30);
set("mana_factor", 40);
set("str", 30);



setup();
}

void unconcious ()
{
  object ob;
  object me = this_object();
  object where = environment (me);

  ob = new ("/d/xiyou/xueshan/obj/cookfood");
  ob->set("name",me->query("name"));
  ob->set("cook/type","hama");
  ob->set("cook/value",5);
  ob->move(where);
  message_vision ("\n$N����һ�ţ����ٶ��ˡ�\n",me);
  destruct (me);
}

void die ()
{
  unconcious();  
}
