//Cracked by Roath
// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
int rank_me();
string ask_chuxian();
string ask_cancel();

void create()
{
  set_name("ţħ��", ({ "niumo wang", "niumo", "wang" }));
  set("title", "������");   
  set("long", "һλ��Ŀ�ΰ�����ޱȵ�ħ����һ˫ţ������ɷ��һ������㡣\n");
  set("gender", "����");
  set("age", 70);
  set("attitude", "heroism");
  set("class", "yaomo");
  set("per", 10);
  set("str", 40);
  set("con", 30);
  set("max_qi", 381700);
  set("max_jing", 381700);
  set("max_jing", 381700);
  set("neili", 381700);
  set("max_neili", 381700);
  set("force_factor", 90);
  set("max_neili", 381700);
  set("neili", 381700);
  set("mana_factor", 45);
  set("combat_exp", 1250000);
  set("combat_exp", 38500000);



  create_family("���ƶ�", 2, "��");

  setup();
  initlvl((500+random(500)),32);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  call_out ("riding",1);
}








void riding ()
{
  command ("mount jinjing shou");
}

void destruct_me (object me)
{
  destruct (me);
}

int check_heads (object me, object ob)
{
  int nb_heads = query("nb_heads")-1;
  object weapon;
  object head;

  me->set("nb_heads",nb_heads);
  if (! ob)
    return nb_heads;
  if (nb_heads <= 0)
    return nb_heads;

  weapon = ob->query_temp("weapon");

  if (! weapon)
    message_vision ("\n$N���һ������$n������ɽ����֮�ƽ�$n��ţͷ����������\n",ob,me);
  else if (weapon->query("skill_type") == "axe")
    message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
  else if (weapon->query("skill_type") == "blade")
    message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
  else if (weapon->query("skill_type") == "sword")
    message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
  else if (weapon->query("skill_type") == "dagger")
    message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
  else if (weapon->query("skill_type") == "staff")
    message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
  else if (weapon->query("skill_type") == "hammer")
    message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
  else if (weapon->query("skill_type") == "spear")
    message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
  else if (weapon->query("skill_type") == "staff")
    message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷɨ��������\n",ob,weapon);
  else if (weapon->query("skill_type") == "staff")
    message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷɨ��������\n",ob,weapon);
  else if (weapon->query("skill_type") == "throwing")
    message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
  else if (weapon->query("skill_type") == "whip")
    message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
  else if (weapon->query("skill_type") == "club")
    message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
  else
    message_vision ("\n$N���һ������$n������ɽ����֮�ƽ�$n��ţͷ����������\n",ob,me);
  
  head = new ("/d/qujing/jilei/obj/head");
  head->move(environment(me));
  return nb_heads;
}

void die ()
{
  object me = this_object();
  object ob = query_temp("last_damage_from");
  object killer=query_temp("my_killer");
  object last =query_temp("last_killed_by");
  string faint=query_temp("last_fainted_from");
 object li = new ("/d/qujing/jilei/npc/li");
  // mon 10/3/98
  if(faint && ob) {
      if(faint!=ob->query("id"))
	  set("nb_heads",40); // someone else help, reset count.
  }
  delete_temp("last_fainted_from");
  if(killer!=ob)
      set("nb_heads",40); // someone else help, reset count.

  // mon 7/30/98
  // to prevent other players help to kill niu.
  if(!last) last=ob;
  else if(last!=ob)
      set("nb_heads",40); // someone else help, reset count.
  
  set_temp("last_killed_by",ob);

  if (check_heads (me, ob) > 0)
  {
    set("qi", 170000);
    set("jing", 170000);
    set("jing", 170000);
    set("eff_qi", 170000);
    set("eff_jing", 170000);
    set("eff_jing", 170000);
    set("neili", 170000);
    set("neili", 170000);
    message_vision ("\nֻ��ţǻ��ҡҡ�λ������һ��ţͷ����\n",me);
    if (ob)
      message_vision ("\n$N�����ӵ�����$n���𹥻���\n",me,ob);
    return;
  }

  if (ob)
  {
    ob->set_temp("obstacle/jilei_niumo_killed",1);
   li->announce_success (ob);
  destruct (li); 
  }
  message_vision ("\n�����������������һ����ţħ���Ҳ��\n",me);
  message_vision ("\n$N����������������ԭ��һֻ���ţ������������\n",me);
  message_vision ("�������߹������ý���˩��ţ�����ϣ���$Nǣ���ˡ�\n",me);
::die();
}

void li_appearing (object who)
{
  


}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  
  kill_ob(ob);
  ob->kill_ob(this_object());
  return 1;
}

int test_player (object who)
{
  string *names;
  string name;



    return 1;
//  if (name == "���湫��")
//    return 1;
  return 0;
}

void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);
  object yumian = present ("yumian gongzhu", where);

  if (! test_player (ob))
  {
    message_vision ("$Nһ˫ţ���۵����㣬���һ�����㣡�㣡����\n",me);
    message_vision ("$N���˴��ţ��ԭ����$n���������ص�ͷһ����\n",me,ob);
    message_vision ("$Nһ�����ֲ�������շ���\n",ob);
    ob->move("/d/qujing/jilei/shidong");
    message_vision ("���䡱��$Nˤ��������\n",ob);
    ob->unconcious();
    return;
  }
  message_vision ("\n$N��ŭ���ĸ�������ð�䰳��ң�\n",me);

  set_temp("my_killer",ob);
  call_out ("checking",1,me,ob);  
  ::kill_ob(ob);
  if (yumian && (! interactive(yumian)) && !yumian->is_fighting())
    yumian->kill_ob(ob);
}

void checking (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (me->is_fighting())
  {
    remove_call_out ("checking");  
    call_out ("checking",1,me,ob);  
  }
  else
  {
    int i = 45 - ob->query("kar");

    if (i < 10)
      i = 10;
    me->set("nb_heads",i+random(10));
  }
}


