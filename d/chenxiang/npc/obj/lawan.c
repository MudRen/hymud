 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit F_FOOD;
inherit ITEM;
#include <ansi.h> 
void create()
{
        set_name( "腊丸", ({ "lawan"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一个拇指大小的腊丸，颜色腊黄，并不很起眼，不知道
吃下去会不会有什么神奇的药效。。。。\n");
                set("unit", "个");
                set("value",0);
                set("food_remaining", 1);
                set("food_supply", 0);
                set("material", "food");
        }
        
}  
int finish_eat()
{
        object me;
        int n;
        
        me = this_player();
        if(!me->query("m_success/义助袁姬") 
                && this_object()->query("real_lawan_id")==me->query("id")) {
            me->set("m_success/义助袁姬",3);
            n = random(20);
            switch( random(4)){
                        case 0: if (me->query("score")>5000) me->add("score",-5000);
                                        else me->set("score",0);        
                                tell_object(me,HIW"你的评价降低了。\n"NOR);
                                break;
                        case 1: me->add("max_neili",n);
                                me->set("Add_force/义助袁姬",n);
                           tell_object(me,HIW"你的内力增加了。\n"NOR);
                                break;
                        case 2: me->add("max_atman",n);
                                me->set("Add_atman/义助袁姬",n);
                                tell_object(me,HIW"你的灵力增加了。\n"NOR);
                                break;
                        case 3: me->add("max_mana",n);
                                me->set("Add_mana/义助袁姬",n);
                                tell_object(me,HIW"你的法力增加了。\n"NOR);
                                break;
                        default: break;
                }
                tell_object(me,HIR"你解开了义助袁姬之谜。\n"NOR);
        }   
        else tell_object(me,"但好像没什么效果。\n");
        destruct(this_object());
        return 1;
}
