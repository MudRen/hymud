// by snowcat 12/8/1997

inherit NPC;
void create()
{
  set_name("����ү", ({"lao wangye", "wangye", "wang", "ye"}));
  set("title", "����");
  set("gender", "����");
  set("age", 60);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 100000);
  set("combat_exp", 50000);

  set_skill("unarmed", 60);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set("max_jing",600);
  set("max_qi",600);
  set("max_jing",600);
  set("max_neili",600);
  set("max_neili",600);
  set("force_factor",50);
  set("eff_dx",10000);
  set("nkgain",50);
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/yuhua") == "done")
    return;
  if (! who->query_temp("obstacle/yuhua_bang"))
    return;
  if (! who->query_temp("obstacle/yuhua_pa"))
    return;
  if (! who->query_temp("obstacle/yuhua_zhang"))
    return;
  if (! who->query_temp("obstacle/yuhua_killed"))
    return;
  i = random(900);
  who->add("obstacle/number",1);
  who->set("obstacle/yuhua","done");
  who->add("combat_exp",i+39000);
       who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"��ͷɽѰ�������������ɽ�Ʒ���ͷʨ�֣�");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(i+39000)+"�㾭��"+
               chinese_number(i*8)+"��Ǳ��"+" ʮ�����ɹ��� ����ɳ����ޣ���\n");
  who->save();
}


