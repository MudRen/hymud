 // staff.c
#include <weapon.h>
#include <ansi.h>
inherit SWORD; 
void create() {
        set_name(YEL"����ľ��"NOR, ({ "staffs" }) );
        set_weight(1000);
        if(clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѹ��ŻƲ�����ͨľ����");
                set("value", 2000);
                set("material", "steel");
                set("rigidity", 80);
                set("wield_msg", "$N��$n�������������С�\n");
                set("unwield_msg", "$N�ɿ������е�$n��\n");
        }
    ::init_sword(40);
}
