#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("筑星耙", ({ "zhuxing pa", "pa", "staff" }) );
  init_staff(40);
  set("unit", "根");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 480);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

