// diamond.c 钻石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIW "钻石" NOR, ({ "diamond" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIW "一粒精光闪闪的钻石。\n" NOR);
                set("value", 5000);
		set("unit", "粒");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
                set("armor_prop/percao", 15);
set("armor_prop/karay",15);
set("armor_prop/armor", 165);

                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
	}
        setup();
}


