 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "�¹�");
        set("long", @LONG
һ��̴���ľ���ϲ����Щ�·����²��пգ�ֱͨ���£�
�ײ�������һ���󶴣��ƺ���������ȥ�����ӵ��Ű����ţ���
Լ���������ǿ����Ů������ϸ�����濴ȥ������һƬ��ڣ�
�ƺ�������Щ���ش�Ļ��ܡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"nroom",
  "down" : __DIR__"andao5",

   ]));



        set("objects", ([
       
//        __DIR__"npc/bandit1" : 5,
                        ]) );

        set("indoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",395);
        set("coor/z",-1);
        set("coor/x",-5);        
        setup();
                replace_program(ROOM);

} 