// fagate.c ϡ�����

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIR "ϡ�����" NOR, ({ "flawless agate" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIR "һ�������˵Ĵ���解�����"
                            "��ۼ���������С�\n" NOR);
                set("value", 10000);
		set("unit", "��");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
                set("armor_prop/percao", 17);
                set("armor_prop/karay",17);
set("armor_prop/armor", 167);

                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}


