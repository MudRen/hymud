
#include <ansi.h>  
#include <armor.h>

inherit NECK;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"��������"NOR, ({ "necklace17"}));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
		set("value", 3900);
		set("material", "gold");
		set("armor_prop/armor", 269);
set("armor_prop/constitution",19);
set("armor_prop/karay",19);
	}
	setup();
}	
