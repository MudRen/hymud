
#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("白纱衣", ({ "cloth","yi" }) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
	 set("long","这是一见白纱衣，看起来有些透明。\n");
     set("material", "cloth");
     set("unit", "件");
     set("value", 40);
     set("armor_prop/armor", 2);
   }
   setup();
}
