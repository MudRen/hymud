 // rope.c
#include <ansi.h>
#include <weapon.h> 
inherit WHIP; 
void create()
{
        set_name( "�����", ({ "whip" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "һ������Ƥ���ɵĳ��ޡ�\n");
                set("value", 20000);
                set("material", "skin");
        }
        ::init_whip(40); 
        set("wield_msg", "$N����������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n"); 
}        
