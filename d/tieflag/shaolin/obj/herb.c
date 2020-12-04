 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
        set_name("经脉图", ({ "经脉图","jingmaitu"}));
        set_weight(600);
        set("no_get",1);
        set("no_shown",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "幅");
                set("long",
                        "一幅难以辨认的经脉图。\n");
                set("value", 700);
                set("material", "stone");
                set("skill", ([
                        "name":                 "hunyuan-yiqi", 
                        "exp_required": 0,              
                        "jing_cost":             50,     
                        "difficulty":   50,     
                        "literate": "banruo-zhang",
                        "max_skill":    49              
                ]) );
        }
} 
