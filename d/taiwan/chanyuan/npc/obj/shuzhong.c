
#include <ansi.h>

inherit ITEM;

int do_zhong(string arg);

void create()
{
   set_name(HIG"����"NOR, ({ "shu zhong","shu","zhong"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "Щ");
     set("long","����һЩ���֡�\n");
     set("nogive_player",1);
   }
   setup();
}

