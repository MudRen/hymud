
#include <ansi.h>

inherit ITEM;

int do_zhong(string arg);

void create()
{
   set_name(HIG"树种"NOR, ({ "shu zhong","shu","zhong"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "些");
     set("long","这是一些树种。\n");
     set("nogive_player",1);
   }
   setup();
}

