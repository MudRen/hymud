 inherit ITEM;
#include <ansi.h>
inherit F_LIQUID; 
void create()
{
        set_name(HIG"������"NOR, ({ "dragon cup", "cup" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("long", "һ�������ɣ�ʢ����̫�����Ƶ���������\n");
                set("unit", "��");
                set("value", 2000);
                set("max_liquid", 1000);
        } 
        set("liquid", ([
                "type": "alcohol",
                "name": "̫������",
                "remaining": 1000,
                "drunk_apply": 1000,
        ]) );
}

