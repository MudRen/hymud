// silver.c
#include <ansi.h>
inherit MONEY;

void create()
{
        set_name(HIY "����" NOR, ({"silver","silver_money"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "silver");
                set("long", "�׻���������,������š�����ƽ׼һ����\n");
                set("unit", "Щ");
                set("base_value", 1000);
                set("base_unit", "��");
                set("base_weight", 33);
        }
        set_amount(1);
}


