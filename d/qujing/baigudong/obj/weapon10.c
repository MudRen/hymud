#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("�����", ({ "gouhun jian", "jian", "club" }) );
  init_staff(30);
  set("unit", "��");
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 240);
    set("material", "wood");
  }
  setup();
}

