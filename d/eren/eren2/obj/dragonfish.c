#include <ansi.h>
inherit ITEM;
inherit F_FOOD; 
void create()
{
                set_name("������", ({ "dragonfish" }) );
    set_weight(500);
    if( clonep() )
            set_default_object(__FILE__);
    else {
        set("long", HIY"һ���������Ե����㣬��Ƭ�����ҹ⻬��\n"NOR);
        set("unit", "��");
        set("value", 5000);
        set("food_remaining", 3);
        set("food_supply", 10);
        set("marks/catfood", 1);
    }
    
} 
void init() {
        ::init();
        call_out("badfish", 120);
} 
void badfish() {
        set("long", "�Ѿ��������ʵ���ɢ����һ���ȳ�ζ��\n");
        set("name", "ɢ�����ȳ�ζ����");
        set("marks/catfood", 0);
        set("value", 0);
}  

