// cloth.c
//
// This is the basic equip for players just login.
#include <ansi.h>;
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIC"����"NOR, ({ "han fu" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value",180000);
                set("no_get",1);
                set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);                
                set("no_pawn",1);
                set("systemmake",1);
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", random(200)+80);
                set("armor_prop/damage", random(100)+50);
        }
        setup();
}

