 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�����Է�");
        set("long", @LONG
û��ױ̨��û���屻��û�н������գ�Ҳû���κλ�������裬����
�����棬ѣĿ���鱦�������ӵľ��£������������ʣ�����֬�ۣ�������
����ɫ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"mirror",
]));
        set("objects", ([
                __DIR__"npc/master" : 1,
       ]) );
        set("coor/x",-1090);
        set("coor/y",80);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
void reset()
{
        object master;
        if(master = present("master guanyin",this_object()))
                destruct(master);
::reset();
}   
