 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��Ѩ�����ֲ�����ָ��������ļž�����һ�ж��Եõ�
���ɲ���ʯ�ڰ�����һ�飬�ƺ��Ǹ���ǣ����������ǣ�
�ƺ�һֱָ��ǰ�档��ǰ��Ƭ�ޱߵĺڰ�����������ʲô�� 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */

  "east" : __DIR__"andao2",
  "west" : __DIR__"andao2",
  "south" : __DIR__"andao4",
  "north" : __DIR__"andao5",

   ]));



        set("objects", ([
       
//        __DIR__"npc/bandit1" : 5,
                        ]) );

        set("indoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",-5);
        set("coor/x",-10);
        setup();
} 