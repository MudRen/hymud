// gao.c

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("����", ({"guo wang", "wang", "king"}));
  set("long", "ͷ��һ������ڣ�����һ�����������һ�������������ۡ�\n");
  set("title", "�ڼ���");
  set("gender", "����");
  set("age", 46);
  set("per", 30);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("combat_exp", 20000000);

  set("max_qi", 1000);
  set("max_jing", 800);
  set("max_jing", 800);
  set("neili", 1000);
  set("max_neili", 1000);
  set("force_factor", 10);
  set("max_neili", 800);
  set("neili", 1200);
  set("mana_factor", 30);
  set_skill("unarmed", 70);
  set_skill("dodge", 70);
  set_skill("force", 70);
  set_skill("parry", 70);
  set_skill("staff", 70);


  set("eff_dx",-30000);
  set("nkgain",180);

  setup();
  initlvl((320+random(330)),61);
  carry_object("/d/obj/cloth/longpao")->wear();
}

void autokill (object me)
{ 
  object where = environment (me);
  object king1 = present ("guo wang 1",where);
  object king2 = present ("guo wang 2",where);

  if (me->is_fighting())
    return;

  if (! king2)
    return;

  if (king2 == me)
    king2 = king1;

  message_vision ("$N��$n���һ����������ħͷ�������������������޵�ģ������\n",
                  me,king2);
  message_vision ("$N��$n����˺����������\n",me,king2);
  me->kill_ob(king2);
  king2->kill_ob(me);
}

void init ()
{
  autokill (this_object());  
}

void die ()
{
  object me = this_object ();
  object longpao = present("long pao",me);
  object where = environment (me);
  object king1 = present ("guo wang 1",where);
  object king2 = present ("guo wang 2",where);

  message_vision ("$N����һ�������İ������ڳ�����������ëʨ�ӵ�ԭ��\n",me);
  message_vision ("\n��ëʨ�ӵ�������յ���ۣ����Ŵ�����\n",me);
  me->set_name("��ëʨ��", ({"blue lion", "lion"}));
  me->delete("title");
  me->delete("long");
  if (longpao)
    destruct (longpao);  
  me->setup();
  me->remove_all_killer();
  me->set("jing",200000);
  me->set("qi",200000);
  me->set("jing",200000);
  call_out("destruct_me",5,me);

  if (! king2)
{
    return;
}
  if (king2 == me)
    king2 = king1;
  king2->announce_success();
}

void destruct_me (object me)
{
  message_vision ("һ�������ס$N����$N৵�һ����ȥ��\n",me);
  message_vision ("����ԶԶ��������������Ц����\n",me);
 
  destruct (me);   
}
