// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit F_UNIQUE;
inherit ITEM;
 
void create()
{
  set_name("�Ͻ���«",({"hu lu", "hu", "lu", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(10000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","ֻ");
    set("value", 10000);
    set("material","cloth");
    set("long","һֻ����͸�ϵĽ��«��\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("unique", 1);
  //set("no_sell", "�Ͻ���«�˷���û�˸���Ҳ��\n");
  //set("no_drop", "�Ͻ���«�˷�����������Ҳ��\n");
  //set("no_give", "�Ͻ���«�˷�����������Ҳ��\n");
  //set("replace_file", "/d/qujing/pingding/obj/hulufake.c");
  set("is_monitored",1);
  setup();
} 

