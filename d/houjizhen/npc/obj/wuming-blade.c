// wuming-blade.c
// by dicky

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name(HIR"��������"NOR, ({ "wuming baodao", "blade"}) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);
		set("disappear",1);
                set("rigidity", 5);
                set("material", "steel");
                set("weapon_prop/dodge", 2);
                set("treasure",1);
                set("wield_str", 25);
                set("wield_msg", "ֻ������һ����$N�������һ�Ѻ���ɭɭ�ı�����\n");
                set("long", "�˵���Լ�ĳߣ�����������ǰ��������������\n");                
                set("unwield_msg","$N����������С�ĵĲ�����\n");               
        }
        init_blade(350);
        setup();
}

