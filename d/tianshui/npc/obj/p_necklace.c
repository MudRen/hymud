// p_necklace.c

#include <ansi.h>

inherit EQUIP;

void create()
{
       set_name("��������", ({ "pearl necklace", "necklace" }) );
       set_weight(8000);
       if( clonep() )
              set_default_object(__FILE__);
       else {
              set("unit", "��");
              set("value", 7000);
              set("material", "cloth");
              set("armor_type", "neck");
              set("armor_prop/armor", 10);
              set("armor_prop/dodge", 5);
       }
}
