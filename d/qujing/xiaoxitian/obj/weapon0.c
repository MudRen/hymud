#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("�߳ݰ�", ({ "qichi pa", "pa", "staff" }) );
  init_staff(35);
  set("unit", "��");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 310);
    set("material", "metal");
  }
  setup();
}

