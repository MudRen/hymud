// ccrystal.c ˮ����Ƭ

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIM "ˮ����Ƭ" NOR, ({ "chipped crystal" }) );
	set_weight(25);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIM "һƬ��ɫ��ˮ����Ƭ��\n" NOR);
                set("value", 2000);
		set("unit", "Ƭ");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
                set("armor_prop/percao", 13);
                set("armor_prop/karay",13);
set("armor_prop/armor", 163);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}


