#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("�ջ��", ({ "shaohuo gun", "gun", "staff" }) );
  init_staff(15);
  set("unit", "��");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 100);
    set("material", "bone");
  }
  setup();
}

