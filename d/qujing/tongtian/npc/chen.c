// rewritten by snowcat on 12.12.1997

inherit NPC;

void create()
{
  set_name("�³���", ({"chen zhanglao", "chen", "zhanglao"}));
  set("gender", "����");
  set("age", 70);
  set("attitude", "friendly");
  set("combat_exp", 50000);
  set("combat_exp", 50000);

  set("per", 35);
  set_skill("dodge", 30);
  set_skill("force", 30);
  set_skill("parry", 30);
  set("max_jing",6000);
  set("max_qi",6000);
  set("max_jing",6000);
  set("neili",5000);
  set("max_neili",5000);
  set("max_neili",5000);
  set("force_factor",5);
  setup();

  carry_object("/d/obj/cloth/choupao")->wear();

}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/tongtian") == "done")
    return;
  if (! who->query_temp("obstacle/tongtian_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/tongtian","done");
  who->add("combat_exp",i+22000);
  
     who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"ͨ��Ӿ�ͯ��Ů��ˮլ���㾫��");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(i+22000)+"�㾭��"+
               chinese_number(i*8)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
  who->save();
}
�
