// jiaohuaji.c
#include <weapon.h>
inherit HAMMER;
inherit F_FOOD;
void create()
{
        set_name("�л���", ({ "jiaohua ji", "chicken", "ji" }) );
        set_weight(550);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һֻ���ź�Ҷ�Ľл�����ɢ�����˱ǵ����������˴������Ρ�\n");
                set("unit", "ֻ");
                set("value", 90);
                set("food_remaining", 8);
                set("food_supply", 80);
                set("wield_msg", "$Nץ��һֻ$n���������е�������\n");
                set("material", "bone");
        }
        init_hammer(1);
        setup();
}
int finish_eat()
{
        if( !query("weapon_prop") ) return 0;
        set_name("�еþ���ļ��ȹ�ͷ", ({ "bone" }) );
        set_weight(150);
        set("long", "һ���еþ���ļ��ȹ�ͷ��\n");
        return 1;
}
