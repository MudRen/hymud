#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + CYN "������" NOR, ({ "tiegu shan", "tigu", "shan" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", NOR + CYN "����һ�������ȣ��������˳���"
                            "������Ϊ��Ѩ�ı�����\n" NOR);
                set("value", 3000);
                set("material", "steel");
                set("wield_msg", "$N�Ӷ����ͳ�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�Żض��\n");
        }
        init_sword(180);
        setup();
}
