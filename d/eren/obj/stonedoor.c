 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
        set_name( "ʯ��", ({ "door"  }) );
        set("unit", "��");
        set("no_get",1);
        set("value",20);
        set("long","
����һ�ȳ��ص�ʯ�ţ�������һ����״��ȱ��(Hole)��
\n");
        set_weight(5000);
        
} 

void init()
{
        add_action("do_touch","move");
} 
int check_needles()
{
        object liver,kidney,stomach, heart, lung, env,*inv;
        object red,green,yellow, white,black;
        env = environment(this_object());
        
        if(!objectp(liver=present("green",env))) return 0;
        if(!objectp(kidney=present("kidney",env))) return 0;
        if(!objectp(stomach=present("stomach",env))) return 0;
        if(!objectp(heart=present("heart",env))) return 0;
                
        inv = all_inventory(liver);
        if( sizeof(inv) != 1) return 0;
        green = inv[0];
        if((string)green->query("name") != "����") return 0;
        
        inv = all_inventory(kidney);
        if( sizeof(inv) != 1) return 0;
        black = inv[0];
        if((string)black->query("name") != "����") return 0;
        
        inv = all_inventory(stomach);
        if( sizeof(inv) != 1) return 0;
        yellow= inv[0];
        if((string)yellow->query("name") != "����") return 0;
        
        inv = all_inventory(heart);
        if( sizeof(inv) != 1) return 0;
        red= inv[0];
        if((string)red->query("name") != "����") return 0;
        
        
// now we have everything, let's open path! and reset this room;
        red->move(env); destruct(red);
        green->move(env); destruct(green);
        yellow->move(env); destruct(yellow);
        white->move(env); destruct(white);
        black->move(env); destruct(black);
        return 1;
} 
int do_touch(string arg)
{
        object me,env;
        if( !arg ) return 0;
        if( arg != "ȱ��" && arg != "hole") return 0;
        me = this_player();
        message_vision("$N����������ʯ����ȥ��\n",me);
        if (me->query("neili")<500)
                return notify_fail("�������������\n");
        
   
                me->add("neili",-500);
                env = environment(this_object());
                message("vision","ʯ�Ÿ¸µض���������¶�������һ�����������ڡ�\n",env);
           message_vision("$Nһ������˰�����ʯ����$N����ֺ����ˡ�\n",me);
                me->move("/d/eren/cavein");
                return 1;
   
        return 1;
}
   
