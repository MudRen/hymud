 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit F_FOOD;
inherit ITEM;
#include <ansi.h> 
void create()
{
        set_name( "����", ({ "lawan"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","����һ��Ĵָ��С�����裬��ɫ���ƣ����������ۣ���֪��
����ȥ�᲻����ʲô�����ҩЧ��������\n");
                set("unit", "��");
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
        if(!me->query("m_success/����Ԭ��") 
                && this_object()->query("real_lawan_id")==me->query("id")) {
            me->set("m_success/����Ԭ��",3);
            n = random(20);
            switch( random(4)){
                        case 0: if (me->query("score")>5000) me->add("score",-5000);
                                        else me->set("score",0);        
                                tell_object(me,HIW"������۽����ˡ�\n"NOR);
                                break;
                        case 1: me->add("max_neili",n);
                                me->set("Add_force/����Ԭ��",n);
                           tell_object(me,HIW"������������ˡ�\n"NOR);
                                break;
                        case 2: me->add("max_atman",n);
                                me->set("Add_atman/����Ԭ��",n);
                                tell_object(me,HIW"������������ˡ�\n"NOR);
                                break;
                        case 3: me->add("max_mana",n);
                                me->set("Add_mana/����Ԭ��",n);
                                tell_object(me,HIW"��ķ��������ˡ�\n"NOR);
                                break;
                        default: break;
                }
                tell_object(me,HIR"��⿪������Ԭ��֮�ա�\n"NOR);
        }   
        else tell_object(me,"������ûʲôЧ����\n");
        destruct(this_object());
        return 1;
}
