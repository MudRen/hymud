// wuming-jian.c
// by dicky

#include <ansi.h>
#include <weapon.h>
inherit SWORD;


void create()
{
        set_name(HIR"��������"NOR, ({ "wuming baojian", "wuming", "sword", "jian"}) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);
                set("rigidity", 5);
                set("sharpness", 3);
                set("material", "steel");
                set("weapon_prop/dodge", 2);
                set("treasure",1);
                set("wield_str", 25);
                set("wield_msg", "ֻ������һ����$N�������һ�Ѻ���ɭɭ�ı�����\n");
                set("long", "�˽���Լ�ĳߣ�����������ǰ��������������\n");                
                set("unwield_msg","$N����������С�ĵĲ�����\n");               
        }
        init_sword(345);
        setup();
}

