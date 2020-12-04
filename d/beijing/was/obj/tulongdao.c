#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(CYN "屠龙刀" NOR, ({ "tulong blade" , "blade" ,"dao", "tulong" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", HIY "这便是号称武林至尊的屠龙宝刀，四尺来长的单刀，竟达一百多斤之重。\n相传其中藏有旷世的大秘密。\n" NOR);
                set("value", 5000);
                set("no_sell", "这样东西不能卖。\n");
                set("rigidity",8000);   
                set("material", "steel");
                set("wield_msg", HIY "$N一声狂笑，从背后抽出那柄号称“"NOR+HIR"武林至尊"NOR+HIY"”的屠龙宝刀高高举起。\n" NOR);
                set("unwield_msg", HIY "$N哈哈一笑，将屠龙宝刀插回背后。\n"NOR);
        }
        init_blade(500);
        setup();
}
