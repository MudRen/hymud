 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "���е���");
        set("long", @LONG
�����Ǹ�ʮ��·�ڣ�����Ĳ����ǰ����ֱ��ͨ������������ģ�����ȴ��һ
�¸�ǽ��ס�ˡ����ǰ������������ɿ��Կ������ĵ�԰̳��������Բ��ֱ��������
����γɵ�Բ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"btdl",
                "south" : __DIR__"ntdl",
                "west" : __DIR__"zddm",
                "southeast" : __DIR__"ztddn",
        ]));
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",-15);
        set("coor/z",-20);
        setup();
}  
