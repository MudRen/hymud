#include <ansi.h>
#include <armor.h>

inherit S_RING;
inherit F_AUTOLOAD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  

void create()
{
	set_name(order[random(13)]+"�������"NOR, ({ "magic ring", "ring" }));
	set("long", HIC"����һ����Զ�����������Ľ�ָ���������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
	set("value", 50000);
	set("material", "gem");
	set("armor_prop/armor", 180);
    set("armor_prop/damage", 80); 
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",5);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",10);
		set("armor_prop/constitution",10);
  
    
	set("armor_type", TYPE_FINGER);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
        set("no_clone",1);
        set("no_pawn",1);
	set("no_beg",1);
	set("no_steal",1);
	setup();
}	

int query_autoload() { return 1; }
