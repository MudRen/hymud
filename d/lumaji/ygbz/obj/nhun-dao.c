// /d/ygbz/obj/ninghun.c
// by yahoo 18:06 99-3-22
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()

{
        set_name(HIW "���걦��" NOR, ({ "ninghun blade", "blade" }) );
          set_weight(50000);
        if (clonep())

                set_default_object(__FILE__);

        else {
                set("unit", "��");
                set("long", "����һ������ɱ���ı�����һ����֪���Ϲ������\n");
                set("no_get", 1);
                set("no_give", 1);
                set("value", 10000);
                set("material", "steel");
        set("wield_msg", HIW "ֻ��$N��ৡ���һ�����һ�����걦���������У�һ�ɵ��������ĺ���\n" NOR);
                  set("unwield_msg", HIW "$N�����е����걦����ص��ʡ���Ҳž��ú����ù�һ�㡣\n" NOR);
        }
        set("rigidity",1000);
    set("no_get",1);
    set("no_drop",1);
        init_blade(1600);
        setup();
}


