 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"��ˮ�����"NOR);
        set("long", @LONG
һ�����������Ľ�ˮ�ӣ��������������ˮ��·�����ٷ磬������������
�������������ʯʯ��ͨ��԰���������ν����·�š����˵�������֮·��������
�ơ������š����������������ߵģ��������ŷ�Ϊ��Ʒ���š�����һ���Ա���ߡ�
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"hall",
                "enter" : __DIR__"taihedian",
        ]));
        set("objects", ([
                __DIR__"npc/jindian_guard" : 2,
        ])); 
        set("outdoors", "fengyun");
        set("coor/x",50);
        set("coor/y",15);
        set("coor/z",0);
        setup(); 
} 
int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    int withtowel=0;
    if( me->query("class") != "official" && dir == "enter" && ob=present("palace guard", this_object()))
    {
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
      
            if( (string)(inv[i]->query("id")) == "silk" &&
                !(int)(inv[i]->query("equipped")))
                return notify_fail(ob->name()+"������������װ�����빬�������\n");
            if( (string)(inv[i]->query("id")) == "silk" )
                withtowel = 1;
        }
        if( !withtowel)
            return notify_fail(ob->name()+"����ŭ�ȣ���û��"+HIR"��"+HIY"��"+HIG"˿�д�"+NOR"���ܽ��룡������\n");
    }
    if( dir == "south" && ob=present("palace guard", this_object()))
    {
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
            if( (string)(inv[i]->query("id")) == "silk")
            {
                tell_object(me,ob->name()+"����ӹ��㽻�ص�"+
                            inv[i]->name()+"�������͹������������\n\n\n"); 
                destruct(inv[i]);
            }
        }  
    }
    return 1;
}   




/*int valid_leave(object me, string dir)
{
        object ob;
        if( me->query("class") != "official" && dir == "enter" && ob=present("palace guard", this_object()))
        {
                return notify_fail(ob->name()+"ŭ�ȣ�����̫�͵�Ҳ��������Щ������ȥ��ô��������\n");
        }
                return 1;
}   


int valid_leave(object me, string dir){
        object silk;
        
        if(obj->query("bellicosity") > 100 || obj->query_temp("weapon") || obj->query("vendetta/authority") || !objectp(silk)) {
                        return notify_fail("�����ʿ��ɫһ����ŭ�ȵ�����ֹ������\n");
                }
        if(objectp(silk) && silk->query("equipped") != "worn")
                        return notify_fail("�����ʿ��ɫ���͵ص���������װ�ã���\n");
                if(objectp(silk) && silk->query("equipped") == "worn"){
                        message_vision("�����ʿһ��ȭ�����������λ"+RANK_D->query_respect(obj) +"���ܹܷԸ����������߲�˿�д����������ߣ�\n\n",
                                        obj); 
                        return 1;
                }
        }       
        }
        return 1;
}*/
