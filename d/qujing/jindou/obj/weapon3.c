#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("长铁爪", ({ "tie zhua", "zhua", "staff" }) );
  init_staff(40);
  set("unit", "柄");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 450);
    set("material", "iron");
  }
  set("wield_msg","$N拿起$n握在手里。\n");
  setup();
}

