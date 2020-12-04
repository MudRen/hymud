// gao.c

inherit NPC;
int give_jade();
int show_king();

void create()
{
  set_name("����", ({"guo wang", "wang", "king"}));
  set("long", "ͷ��һ������ڣ�����һ�����������һ�������������ۡ�\n");
  set("title", "�ڼ���");
  set("gender", "����");
  set("age", 46);
  set("per", 30);
  set("dex", 200);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("combat_exp", 8000000);

  set_skill("unarmed", 300);
  set_skill("dodge", 300);
  set_skill("parry", 300);
  set("max_jing",58000);
  set("max_qi",58000);
  set("max_jing",58000);
  set("max_neili",58000);
  set("neili",58000);
  set("max_neili",58000);
  	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_temp("apply/parry",200);
	set_temp("apply/dodge",200);
	set_temp("apply/armor",8500);
	
  set("eff_dx",15000);
  set("nkgain",90);

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void announce_success()
{
  object me = this_object();
  object where = environment(me);
  string id = me->query("my_saver");
  object who;

  if (! id)
    return;

  who = present(id,where);
  if (! who)
    return;

  remove_call_out ("announce");
  call_out ("announce",8,me,who);
}

void announce(object me, object who)
{//disabled announce and reward...
  int i;

  if (who->query_temp("obstacle/wuji") != "saved")
    return;

  if (who->query("obstacle/wuji") == "done")
  {
    //tell_object (who,"���Ѿ�������һ�أ�ʲô���ò����ˣ�\n");
    return;
  }  

  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/wuji","done");
  who->add("combat_exp",i+15000);
       who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("thank "+who->query("id"));
  command("chat "+who->query("name")+"�ڼ������һ�����������������Ǭ����");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(i+15000)+"�㾭��"+
               chinese_number(i*8)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
  who->save();
  command("follow none");
}

