 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
��ש���̲ݡ��Ͷ���û��ʲô������ʮ�ɷ�Բ�ĵط��Ե��ر��
Э��������Ҳ��С����������������������Զ������˺���˶���
�Ĺ���ͤ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
          "east" : __DIR__"cxs3",
          "west" : "/d/wolfmount/yinroad1",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-510);
        set("coor/y",-540);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
