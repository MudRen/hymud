inherit NPC;
#include "/d/migong/romnpc2.c"
string expell_me(object me);

void create()
{
  set_name("����Ϻ��", ({"changtui xiabing","xiabing"}));
  set("gender", "����");
  set("age", 25);
  set("title", "�̲�̶��ͷ��������");
  set("long","�̲�̶�������ͻ��ƶ����н���,�������������͵�,˳��Ҳ��Щͽ�ܡ�\n");
  set("combat_exp", 100000+random(3000));
  set("combat_exp", 100000);
  set("per", 15);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set_skill("unarmed", 70);

  set("max_jing",800);
  set("max_qi",800);
  set("neili", 400);
  set("max_neili", 400);
  set("force_factor", 20);
  set("neili", 400);
  set("max_neili", 400);
  set("mana_factor", 20);



  create_family("�̲�̶", 3, "��");

  setup();
initlvl((200+random(200)),54);
  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
  carry_object("d/obj/weapon/stick/mugun")->wield();


}




