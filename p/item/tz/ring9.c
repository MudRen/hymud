#include <ansi.h>
#include <armor.h>

inherit S_RING;
inherit F_AUTOLOAD;

void create()
{
	set_name(HIM"�������"NOR, ({ "magic ring", "ring" }));
	set("long", HIC"����һ����Զ�����������Ľ�ָ���������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
	set("value", 50000);
	set("material", "gem");
	set("armor_prop/armor", 160);
        set("armor_prop/constitution",5);
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
