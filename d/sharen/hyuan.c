 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
��Ŀ�컨�̲ݡ�����׸룬����̨ͤ¥��С����ˮ��Ȼ��
һ�ж�����ɭɭ���������·�����ˮ�������������񣬻���ʧɫ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"caodi",
  "east" : __DIR__"lang4",

   ]));



        set("objects", ([
       
        __DIR__"npc/bandit3" : 2,
        __DIR__"npc/bandit4" : 2,
        __DIR__"npc/bandit5" : 2,
                        ]) );

        set("outdoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",0);
        set("coor/x",-10);
        setup();
                replace_program(ROOM);

} 