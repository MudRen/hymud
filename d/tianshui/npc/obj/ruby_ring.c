// ruby_ring.c

#include <ansi.h>

inherit EQUIP;

void create()
{
       set_name(HIR "�챦ʯ"+ NOR "��ָ", ({ "ruby ring", "ring" }) );
       set_weight(8000);
       if( clonep() )
              set_default_object(__FILE__);
       else {
              set("unit", "��");
              set("value", 7000);
              set("material", "cloth");
              set("armor_type", "finger");
              set("armor_prop/armor", 10);
              set("armor_prop/dodge", 5);
       }
}
