// FOOD in new file_standard. Lin edited in JUNE 1997
inherit ITEM;
inherit F_FOOD;

#include <ansi.h>



void create()
{
    set_name(BLK"������"NOR, ({"he shou wu","shouwu"}));
    set_weight(400);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "һ�øոմӵ����ڳ����ĺ����ڣ�����ȭͷ��ô��\n"
                    "�������Σ�ͨ���ںڡ�\n");
        set("unit", "��");
set("value", 6000);
set("over_value", 1000);
        set("food_remaining", 4);
        set("food_supply", 120);
        set("eat_msg","$N����$nҧ��һ�ڣ�����ܲ�һ��������ȥ.\n");
        set("end_msg","$N��ʣ�µ�$n�Եĸɸɾ���.\n");
    }
}
