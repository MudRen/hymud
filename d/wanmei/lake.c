 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ɽ�о޺�");
        set("long", @LONG
��ˮ�峺���ף�����ɫ��ˮ���沨ҡ�ڡ�ββС�㻺���ζ���������ˮ��
֮�䡣һϯ�ٲ�к����У�����¡¡֮�����ص���Ⱥɽ�����������С������
��������γ�һ��СϪ������ɽ�¡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jungle",
  "east" : __DIR__"waterfall",
]));
        set("outdoors","wanmei");
        set("coor/x",210);
        set("coor/y",-290);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}   
