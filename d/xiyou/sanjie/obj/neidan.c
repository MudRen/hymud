// neidan.c �����ڵ�

#include <ansi.h>

inherit ITEM;



void create()
{
  set_name(HIM "�����ڵ�" NOR, ({"chunyang neidan","neidan","dan"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "������ʦ�������İ��깦�����ɵ��ڵ���\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  
  set("is_monitored",1);
  setup();
}

