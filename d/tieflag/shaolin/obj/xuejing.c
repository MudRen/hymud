 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIR"����Ѫ��"NOR, ({ "xuejing","jing"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ������ʦ��ʱ��ʮ��������Ѫд�ɵĻ���Ѫ��\n");
                set("value", 700);
                set("material", "stone");
                set("skill", ([
                        "name":                 "literate", 
                        "exp_required": 1000000,                
                        "jing_cost":             10,     
                        "difficulty":   10,     
                        "literate": "banruo-zhang",
                        "liter_level":  50,
                        "max_skill":    99              
                ]) );
        }
}