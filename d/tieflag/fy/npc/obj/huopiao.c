 inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("��Ʊ", ({ "huopiao" , "��Ʊ"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�Ž�ʨ�ھֵĻ�Ʊ\n");
                set("value", 1);
        }
}     
