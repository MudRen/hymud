inherit NPC;
#include <ansi.h>
string gloat();
string ask_me();

void create()
{
  set_name("������", ({ "jiang ziya", "jiang" }));
  set("title", HIW"���������"NOR);
  set("nickname", HIR"̫����"NOR  );
  set("gender", "����");
  set("age", 65);
  set("str", 100);
  set("per", 100);
  set("cor", 100);
  set("cps", 100);
  set("long","�����ǵ������̨��һͳ�����̫������������");
  set("combat_exp", 3000000);
  set("daoxing", 2000000);

 set("family/family/name", "��ԯ��Ĺ"); 
 

  setup();
  carry_object("/d/obj/weapon/whip/longsuo")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}

