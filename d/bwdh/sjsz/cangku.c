//Cracked by Kafei
// cangku to store all players's stuff

inherit ITEM;
#include <ansi.h>

void create()
{
  set_name("�������ֿ�", ({ "cangku", "ku"}) );
  set_weight(100000000);
  set_max_encumbrance(500000000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "�������ֿ���ű��������ǵ�������Ʒ��\n");
    set("value", 1000000);
    set("material", "steel");
    set("no_get",1);
    set("no_clean_up", 1);
  }
  setup();
}