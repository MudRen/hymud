 inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
void create()
{
        set("short", "��÷ɽׯ");
        set("long", @LONG
������ǰ��֦�⽻���÷�֣�ÿ����ѩ����֮������ɽ÷��
���࿪�š�����֮�У�ѩ�����÷��ӳ�ɻԣ�����ʤ�ա�÷֦��
ӳ֮�У����嶣�ˣ��������֡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road2",
  "east" : __DIR__"gate",
]));
        set("outdoors", "wanmei");
        set("coor/x",130);
        set("coor/y",-400);
        set("coor/z",30);
        setup();
        replace_program(ROOM);
}    
