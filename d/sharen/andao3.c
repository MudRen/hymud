 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��Ѩ��Բ�����ɣ�������ǰ�������˼��⣬��������С����������
��СС��ľ���������ҵķ���Щ��������ᣬ�ҳ��ѻ��˰�硣��Щ
�䶼��Щƽ��������֮����������˵���Ѩ�﷢����Щ������ȴӲ��
��˵���������ء��������ż����ؼ㣬����д�ŵľ���Щ����粴ʣ�
���ҿ���Ů�ӵ��ֱʡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"andao2",
  "north" : __DIR__"andao4",

   ]));



        set("objects", ([
       
        __DIR__"npc/guo" : 1,
                        ]) );

        set("indoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",-5);
        set("coor/x",-5);
        setup();
} 