 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�˸���");
        set("long", @LONG
����һ���ų�����ķ��꣬����˵�Ǹ����꣬������˵�Ǹ���
�ֱߵĴ��ŵ������ѳ�����ɢ�ط��ڼ��ŷ���ǰ����������������
��Ͳ����������˿��ӡ�һ��С���ڿ��������ȥ�к����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cxs2",
]));
        set("objects", ([
        __DIR__"npc/cx_waiter": 1,
                        ]) );
        set("coor/x",-490);
        set("coor/y",-530);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       