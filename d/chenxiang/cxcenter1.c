 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
// #include "/questnpc/lovestory1/event_place.h"
void create()
{
        set("short", "����̨");
        set("long", @LONG
���˵�����Ǹ��㳡������˵�����Ǹ��޴����ͤ���Ϸ�
�������ȣ�����ïʢ�������ͤ��Ȼ����Ȼ�γɣ��������Ҷ��
����˽�֯��һ�����ǹ��񹦡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs1",
  "west" : __DIR__"cxw1",
  "south" : __DIR__"cxs2",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-520);
        set("coor/z",0);
        setup();
 
} 
/* int valid_enter(object me)
{ 
        if(me->query("lovestory1"))
                add_trigger_count(me);
        return 1;
}   
*/