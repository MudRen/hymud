// fjade.c 稀世翡翠

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIG "稀世翡翠" NOR, ({ "flawless jade" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIG "一块美得无与伦比的大翡翠。\n" NOR);
                set("value", 10000);
		set("unit", "块");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
                set("armor_prop/percao", 17);
                set("armor_prop/karay",17);
set("armor_prop/armor", 167);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
	}
        setup();
}


