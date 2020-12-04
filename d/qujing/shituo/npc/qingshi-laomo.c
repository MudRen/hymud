// qingshi-laomo.c...weiqi, 97.09.15.

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("��ʨ��ħ", ({"qingshi laomo", "qingshi", "laomo"}));
	set("title", "����� ʨ����");
	set("gender", "����" );
	set("age", 63);
	set("per", 112);//no rongmao description.

	set("long", "��λ��ʨ��ħ��ʨ��ɽ��ң���������������н��顣��\n");
	set("class", "yaomo");
	set("combat_exp", 53800000);
	set("daoxing", 1000000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 2, "����");



	set("max_kee", 1000);
	set("max_jing", 600);
	set("force", 1600);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 60);
	set("mana_factor", 25);

	set("eff_dx", -200000);
	set("nkgain", 400);

	setup();
	   initlvl((700+random(700)),7);
	carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");

object taishang = new (__DIR__"pusa");
  if (ob)
  {
    ob->set_temp("obstacle/shituo1_killed",1);
    taishang->announce_success (ob);
  destruct (taishang); 
  }
  message_vision ("\n$N�޿��κε���������ԭ����һֻ����\n",me);
  message_vision ("\n���������ߡ�\n",me);
  

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

  ::kill_ob(ob);
}
