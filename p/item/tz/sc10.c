// necklace.c �Ǵ�
#include <ansi.h>   
#include <armor.h>
 
inherit SURCOAT;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"��Ԩ�Ǵ�"NOR, ({ "surcoat10"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
		set("long", "����һ��Ƥ�ʵ���Ԩ�Ǵ������Ա���������\n");
		set("value", 2100);
		set("armor_prop/dodge", 15);
set("armor_prop/intelligence",15);
set("armor_prop/armor", 132);
	}
	setup();
}
