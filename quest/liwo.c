#include <ansi.h>
inherit ITEM;

void create()
{
    int i; 
    string *names = ({
        WHT"ÕäÖé"NOR,RED"ôä´ä"NOR,MAG"Âêè§"NOR,HIG"±ÌÓñ"NOR,HIW"Éºº÷"NOR,HIR"Ã¨¶ùÑÛ"NOR,GRN"×æÄ¸ÂÌ"NOR
    });
    i = random(7);
    set_name( names[i], ({ "treasure stone" }));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
set("long", "ÆæÕäÒì±¦£¬¼ÛÖµÁ¬³Ç£¬ÕæÁîÈËÑÛºì°¡¡£\n");
                set("value", 50000);
                set("material", "paper");
		 
         }
}
