 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�Ȿ���Ǿ���ׯ�ľ����ã������������˼ҵ�˥�ܣ�
����ֻ����һЩû�˴��ߵ���ľ����������������������
���Ѿ�������ʰ�����ײ���������ɴ�����������ĵ��У�
��һ����ׯ�ص���λ����཭���˵�������Ȧ�������ܡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"qyuan",


   ]));



        set("objects", ([
       
        __DIR__"npc/bandit1" : 1,
        __DIR__"npc/bandit2" : 1,
        __DIR__"npc/bandit3" : 1,
        __DIR__"npc/bandit4" : 1,
        __DIR__"npc/bandit5" : 1,
                        ]) );

        set("indoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",0);
        set("coor/x",-5);
        setup();
                replace_program(ROOM);

} 