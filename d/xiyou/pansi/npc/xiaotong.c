// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("Сͯ", ({"xiao tong", "tong"}));
  set("gender", "����");
  set("age", 12);
  set("per", 25);
  set("long", "һλͷ�����ݵĵ�ͯ��\n");
  set("attitude", "friendly");
  set("max_qi", 200);
  set("max_jing", 200);
  set("max_jing", 200);
  set("neili", 200);
  set("max_neili", 200);
  set("neili", 200);
  set("max_neili", 200);
  set("combat_exp", 5000);
  set("force_factor", 11);
  set_skill("unarmed", 30);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}

