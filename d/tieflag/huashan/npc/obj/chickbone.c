 // pearl.c
#include <weapon.h> 
inherit THROWING; 
void create()
{
        set_name("����ͷ", ({ "bone", "chicken bone" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "һ����ͨ�ļ���ͷ\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 1);
                set("base_value", 1);
//              set("stone",1);
        }
        set_amount(50);
        ::init_throwing(10);
}   
