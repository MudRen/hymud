#include <ansi.h>;

inherit ITEM;

void create()
{
        set_name(HIY"靖海刺杀令"NOR, ({ "sha ling", "sha" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一个两寸长的令牌,上面刻着[杀]个大字。\n");
                set("value", 500);
        }
}

