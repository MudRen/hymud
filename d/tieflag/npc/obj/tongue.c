#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(HIG"ɽȸ��"NOR, ({"bird tongue","tongue"}) );
    set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "ɽȸ����ͷ�������ޱȣ���˵�ǹ�͢�����ʳ֮һ��\n");
                set("lore",1);
                set("unit", "��");
                set("value", 3000);
                set("food_remaining", 10);
                set("food_supply", 60);
        }
    
}      
