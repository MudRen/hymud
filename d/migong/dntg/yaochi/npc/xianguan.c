
#include <ansi.h>

inherit NPC;

void create()
{

  set_name("����ɹ�",({ "zaojiu xianguan","xianguan","xian" }) );
  set("can_sleep",1);
  set("gender", "����" );
  set("long", "һλ��緽���ܽ�عڵ��ɳ������ھƸ�ǰæµ�š�\n");
  set("age", 100+random(100));
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 50);
  set("combat_exp",40000);
  set("combat_exp",40000);
  set("neili",500);
  set("max_neili",500);
  set("force_factor", 100);
  set("max_qi", 4000);
  set("max_jing", 4000);
  set("max_mana", 4000);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",150);
  set_skill("dodge",100);
  set_skill("parry",200);
  set_skill("spear",100);
  set_skill("force",100);
  set("no_get","����ɹٶ������̫���ˡ�\n");
  setup();
  carry_object(__DIR__"xianpao")->wear();
}
