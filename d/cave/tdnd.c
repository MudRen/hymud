 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "�춫�ϵ�");
        set("long", @LONG
����С�������ط���·�ߣ��еĻ�װ����ʪʪ����������
��Ҫ�����͵���ĵط�������һЩ��֪�����ֵĹ��߶��ѷ�����
��ƺ�ȫ����������ɽ�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"dnm",
  "east" : __DIR__"dnj",
]));
        set("objects", ([
        __DIR__"obj/dolly": 2,
                        ]) );
        set("indoors", "cave");
        set("coor/x",-32);
        set("coor/y",-24);
        set("coor/z",-20);
        setup(); 
}  
