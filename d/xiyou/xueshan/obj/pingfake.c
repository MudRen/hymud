// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
      set_name("��������ƿ",({"yinyang erqi ping", "ping", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(100000000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","ֻ");
    set("value", 100);
    set("material","cloth");
      set("long","������������������������װ��ƿ�У�һʱ���̻�Ϊ��ˮ��\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("fake", 1);
    set("no_sell", "��������ƿ�˷���û�˸���Ҳ��\n");
    set("no_give", "��������ƿ�˷�����������Ҳ��\n");
  set("is_monitored",1);
  setup();
} 

