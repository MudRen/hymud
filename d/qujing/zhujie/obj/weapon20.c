#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("���ǰ�", ({ "zhuxing pa", "pa", "staff" }) );
  init_staff(40);
  set("unit", "��");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 480);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

