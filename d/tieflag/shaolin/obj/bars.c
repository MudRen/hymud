 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
        set_name("���ܵ�����", ({ "bars"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ�ſ��ŵ��¾�������\n");
                set("value", 70);
                set("material", "iron");
                set("no_get",1);
                set("no_shown", 1);
                set("no_drop",1);
                set("skill", ([
                        "name":                 "force",        
                        "exp_required": 0,              
                        "jing_cost":             50,     
                        "difficulty":   129,     
                        "max_skill":    179              
                ]) );
        }
}      
