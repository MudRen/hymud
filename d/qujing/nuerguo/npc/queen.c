// created 4/5/1997 by snowcat
#include <ansi.h>
#define NAME "������˪�ɺ�"

inherit NPC;

void create()
{
  set_name(NAME, ({"xiliang xianhou", "queen"}));
  set("title", "����Ů��");
  set("gender", "Ů��");
  set("age", 23);
  set("long", "������˪�ɺ���Ů��\n");
  set("combat_exp", 1000000);
  set("combat_exp", 1000000);

  set_skill("snowsword", 100);
  set_skill("sword", 100);
  set_skill("unarmed", 100);
  set_skill("dodge", 120);
  set_skill("parry", 120);
  set_skill("dragonstep", 120);
  map_skill("dodge", "dragonstep");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("neili", 900);
  set("max_neili", 900);
  set("force_factor", 10);

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/obj/weapon/sword/feijian")->wield();
}

void init()
{
  ::init();
}

void announce_success(object who, string reason)
{//disabled announce and reward...
  int i;

  i = random(800);
if (who->query("obstacle/nuerguo") == "done")
return;
  who->add("obstacle/number",1);
  who->set("obstacle/nuerguo","done");
  who->add("combat_exp",i+28000);
     who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+reason+"��˳����������һ�أ�");
  command("chat �������±�����棡");
tell_object(who,"��Ӯ����"+chinese_number(i+28000)+"�㾭��"+
               chinese_number(i*8)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
  who->save();
  message_vision (HIY NAME+"��һ�������������ʧ��\n" NOR,who);
}

void refuse_player(object who)
{
  string name;
  name = who->name();
  message_vision (HIY NAME+"ͻȻ�Ӱ�����������$Nҡҡͷ��"+
                  "���Ѵ���������һ���ˡ���ȥ����ȡ���ɡ�\n" NOR,who);
  message_vision (HIY "˵��"+NAME+"��һ�������������ʧ��\n" NOR,who);
}

void stop_access(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"��һ�Ű������Գ�������$N��"+
                  "����δ����������һ�أ��Բ���\n" NOR,who);
  message_vision (HIY "˵�հ���ӵ��"+NAME+"�ڿ�����������ʧ��\n" NOR,who);
}
�
