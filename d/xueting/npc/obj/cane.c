// buddha_staff.c
#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("����", ({ "cane" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��Ӳľ���ȣ���Ϊ����ʹ�ö��Եù⻬��\n");
                set("value", 600);
                set("material", "wood");
                set("wield_msg", "$N�ó�һ��$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_staff(7);
        setup();
}
