//Cracked by Roath
#include <ansi.h>

inherit NPC;

string *names = ({
  "��ͯ",
  "�ɽ�",
  "�ɹ�",
  "����",
});

string *ids =   ({
   "xian tong",
   "xian jiang",
   "xian guan",
   "xian li",
});

void create()
{

  int i;

  i=random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("gender", "����" );
  set("age", 33);
  set("long", "���ʹ�̫���Ͼ������������������ջ���ǰ�ܺ�\n");
  set("class", "xian");
  set("combat_exp", 25000);
  set("daoxing", 50000);

  set("attitude", "peaceful");


  set("max_qi", 500);
  set("max_jing", 500);
  set("mana", 700);
  set("max_mana", 700);
  set("mana_factor", 20);
  set("neili", 800);
  set("max_neili", 800);
  set("force_factor", 5);



  setup();
carry_object(__DIR__"xianpao")->wear();
}


