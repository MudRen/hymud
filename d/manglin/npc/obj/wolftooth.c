 // pearl.c
#include <weapon.h> 
#include <ansi.h>
inherit THROWING; 
void create()
{
        set_name(HIY"������"NOR, ({ "wolf tooth", "tooth" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "һ�Ŵ���������������Ӳ�Ҽ����������Ͽ��˸�ӬͷС�֡�������\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 1);
                //set("for_create_weapon",1);
                set("base_value", 1);
                set("stone",1);
        }
        set_amount(99);
        init_throwing(100);
        setup();

}   
