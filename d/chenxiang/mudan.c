 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ĵ����");
        set("long", @LONG
���ﶼ�ǻ������ָ����Ļ����Ŷ��Ų����ˣ�ֻ�ö��ŵ��ֱ����ˡ�
����ǵ�����һ���ļ�������ô�ĺã��ʻ��������ر����ʢ�������
������ԭ��Ư�����ˣ�����Ҳ���˶��ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cxs5",
]));
        set("objects", ([
        __DIR__"npc/flowerseller": 1,
                        ]) );
        set("coor/x",-510);
        set("coor/y",-560);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
