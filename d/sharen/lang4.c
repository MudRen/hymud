 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ͽ��Ϸ��ĵ񻨳����칤�ǳ����£�������
ϧ�˿������˻ҳ������������ȱ��ϵ��������в���
�������̵ĺۼ���������������򶷵Ľ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"lang3",
  "south" : __DIR__"lang5",
  "west" : __DIR__"hyuan",

   ]));



        set("objects", ([
       
        __DIR__"npc/bandit1" : 5,
                        ]) );

        set("outdoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",0);
        set("coor/x",-8);
        setup();
                replace_program(ROOM);

} 