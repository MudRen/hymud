 //XXDER
inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR"大还丹"NOR, ({ "dan" }) );
    set_weight(5);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "这是有起死回生功效的大还丹．\n");
        set("unit", "颗");
        set("value", 0);
        set("food_remaining", 1);
        set("food_supply", 0);
        set("material", "food");
    }
        setup();
} 
int finish_eat()
{
    object me;
    int gin, kee, sen, c;
    me = this_player();
    gin = (int) me->query("max_jing");
    kee = (int) me->query("max_qi");
    sen = (int) me->query("max_sen");
    if(me->query("force") >=1500)
        message_vision( HIR "$N深深吸了一口气，运功将药力化开。\n"NOR, me);
    else
    {
        message_vision(HIB"$N内力不够无法化开药力。\n"NOR, me);
        gin/=2;kee/=2;sen/=2;
    }
    c=random(3);
    if(c==0)
    {
        me->set("eff_jing",gin);
        me->set("jing", gin);
    }
    else if(c==1)
    {
        me->set("eff_qi",kee);
        me->set("qi", kee);
    }
    else
    {
        me->set("eff_sen",sen);
        me->set("sen", sen);
    }
    return 0;
}    
