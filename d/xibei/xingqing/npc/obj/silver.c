// silver.c
#include <ansi.h>
inherit MONEY;

void create()
{
        set_name(HIY "银子" NOR, ({"silver","silver_money"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "silver");
                set("long", "白花花的银子,上面刻着“户部平准一两”\n");
                set("unit", "些");
                set("base_value", 1000);
                set("base_unit", "两");
                set("base_weight", 33);
        }
        set_amount(1);
}


