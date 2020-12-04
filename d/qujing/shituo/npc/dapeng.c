// dapeng.c...weiqi, 97.09.27.

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("��������", ({"dapeng mingwang", "dapeng", "mingwang", "wang"}));
	set("title", "������ ��ħ��");
	set("gender", "����" );
	set("age", 45);
	set("per", 30);
	set("str", 30);
	set("long", "��λ����������ȷ����������˵��������������Ҳ�е����ݹ�ϵ��\n���������ġ��˾ˡ������������ֿ�ȸ���������ˣ�ȴҲ�������࣬\n��������֮�ʸ����Ž��������ƽ������ľ��Ǻ��С�\n");
	set("class", "yaomo");
	set("combat_exp", 51800000);
	set("daoxing", 39000000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 1, "��ʦ");
	set("rank_info/respect", "����");
    

	set("max_kee", 3500);
	set("max_jing", 3500);
	set("force", 3500);
	set("max_force", 1800);
	set("mana", 4000);
	set("max_mana", 2000);	
	set("force_factor", 120);
	set("mana_factor", 100);

	set_temp("apply/damage", 50);
	set_temp("spply/armor", 50);
	set_temp("apply/dodge", 50);
   
            setup();
            initlvl((750+random(750)),3);
	carry_object("/d/obj/cloth/choupao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
        carry_object("/d/qujing/shituo/obj/pingreal");
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object fabao = present ("fabao",me);
object taishang = new (__DIR__"pusa");
  if (ob)
  {
    ob->set_temp("obstacle/shituo3_killed",1);
    taishang->announce_success (ob);
  destruct (taishang); 
  }
  message_vision ("\n$N�޿��κε���������ԭ����һֻ������\n",me);
  message_vision ("\n����������ߡ�\n",me);
  
  if (fabao)
  {
    message_vision ("������һֻ$n��\n",me,fabao);
    fabao->move(environment(me));
  }
  else
    message_vision ("��\n",me);
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
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (fabao)
    fabao->ji_ob (ob);

  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}