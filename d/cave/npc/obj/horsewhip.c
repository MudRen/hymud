 // rope.c
#include <ansi.h>
#include <weapon.h> 
inherit WHIP; 
void create()
{
        set_name( BLK"�������"NOR, ({ "horse whip","whip" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "һ����������ޣ������Ϲ����˵��̡�\n");
                set("value", 5000);
                set("material", "skin");
        }
        ::init_whip(555); 
        set("wield_msg", "$N����������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n"); 
}       
