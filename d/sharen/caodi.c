 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
ͥ԰���ҹɫ��ī���ƺ�����������Ӱ��ֻ���÷紵��Ҷ��
�����Ҳ�ڵͳ���������ǰ���᷿ľ�����ѷ����͸�������ɵ�
�ƹ⣬�����ڲ�סҡ�Ρ���ľ����ת��ת��������һ����ɽ���Ӽ�
ɽ���м䴩��ȥ������һ������ɭɭ��¥��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"guan",
  "east" : __DIR__"hyuan",

   ]));



        set("objects", ([
       
        __DIR__"npc/bandit1" : 1,
        __DIR__"npc/bandit2" : 1,
        __DIR__"npc/bandit3" : 1,
        __DIR__"npc/bandit4" : 1,
        __DIR__"npc/bandit5" : 1,
                        ]) );

        set("outdoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",0);
        set("coor/x",-15);
        setup();
        create_door("west", "��ͭ��", "east", DOOR_CLOSED); 
} 