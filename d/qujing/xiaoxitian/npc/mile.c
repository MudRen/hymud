// rewritten by snowcat on 4.12.1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("���շ���", ({"mile fozu", "mile", "fozu"}));
  set("gender", "����");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 1250000);
  set("combat_exp", 5000000);

  set("per", 25);
  set_skill("dodge", 180);
  set_skill("force", 180);
  set_skill("parry", 180);
  set_skill("spells",180);
  set_skill("staff",180);

  set("max_jing",1800);
  set("max_qi",1800);
  set("max_jing",1800);
  set("neili",1800);
  set("max_neili",1800);
  set("max_neili",1800);
  set("force_factor",125);
  setup();
initlvl((600+random(600)),47);
  carry_object("/d/obj/cloth/changpao")->wear();

}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (! who)
    return;
  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/xiaoxitian") == "done")
    return;
  if (! who->query_temp("obstacle/xiaoxitian_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/xiaoxitian","done");
  who->add("combat_exp",i+34000);
       who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"С����������գ�С������սʤ��ü�Ϸ�");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(i+34000)+"�㾭��"+
               chinese_number(i*8)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
  who->save();
}

