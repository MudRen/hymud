 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","�ƻ�ͤ");
  set("long",@LONG
ɽ�дӴ��򶫿�ʼ���ͣ�һ����ͤǰ��һ�ô������ݳ��ƽ�
�������ڴ�˨�������÷���֮�ȳ��������дУ�������ա����
��ɽ�߶��ڴ�Ъ�š�������ǰ�У�����Ȫ�Ǽ����ˡ�
LONG
  );
  set("exits",([
         "west"  :__DIR__"shanjiao.c",
         "eastup":__DIR__"qiyan.c",
         "east" : "/d/tieflag/road",
         "south" : "/d/jinan/gate"
               ]));
        set("objects", ([
                __DIR__"npc/horse" : 1,
                __DIR__"npc/climber" : 2,
       ]) );
        set("outdoors", "qianfo");
  set("coor/x",30);
        set("coor/y",2000);
        set("coor/z",1);
        setup();
}
void init()
{
        add_action("do_climb", "climb");
        if( this_player() ) {
                tell_room(__DIR__"tree1", this_player()->name() + "����

�����˹�����\n");
        }
} 

int do_climb(string arg)
{
        if( arg!="tree" ) return 0; 
        message_vision("$N�ֽŲ��ã����ݵ���������ͤǰ�Ĵ�����\n",
                this_player()); 
        tell_room(__DIR__"tree1", this_player()->name() + "������������

����\n");
        this_player()->move(__DIR__"tree1"); 
        return 1;
} 
int valid_leave(object me, string dir)
{
        if (dir=="eastup") dir="east";
        tell_room(__DIR__"tree1",
                "���µ�" + me->name() + "��" + to_chinese(dir) + "�뿪��

��\n");
        if (dir=="east") dir ="eastup";
        return 1;
}       

