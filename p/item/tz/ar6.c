#include <ansi.h> 
#include <armor.h>

inherit ARMOR;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
        set_name((order[random(13)])+"��ѩ����"NOR, ({"pifen6"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
     set("long", "һ����ѩ���磮\n");
                set("material", "steel");
                set("value", 2900);
                set("armor_prop/armor", 163);
set("armor_prop/damage", 16);
set("armor_prop/attack", 15);
        }
        setup();
}


