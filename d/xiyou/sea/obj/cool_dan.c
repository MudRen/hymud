#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
  set_name(HIC "��ˮ��" NOR, ({"bishui dan", "dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "�����͵�һ�ű�ˮ����\n");
    set("value", 500);
    set("no_sell", 1);
  }
  
  setup();
}

