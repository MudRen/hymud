 // waterskin.c
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID; 
void create()
{
        set_name("��ƿ", ({ "wine bottle", "bottle" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ʽ�����ӵľ�ƿ��\n");
                set("unit", "��");
                set("value", 20);
                set("max_liquid", 450);
        } 
        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "alcohol",
                "name": "���",
                "remaining": 450,
                "drunk_apply": 5,
        ]) );
} 
