//bamboo.c
//created 5-30-97 pickle

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
  set_name("����", ({"bamboo piece", "mace", "bamboo", "piece"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 100);
    set("material", "wood");
    set("long", "һ�����񣬴������Ϊ����ˮ��ԭ��������������ġ�\n");
    set("wield_msg", "$N����һ��$n�����˸���ʽ��\n");
    set("unwield_msg", "$N��$n������䡣\n");
  }
  
  init_staff(5);
  setup();
}

