//1997-3-10 by qyz
#include <room.h>

inherit ROOM;



void create()
{
        set("short","ͥԺ");
        set("long",@LONG
������һ��ͥԺ��Ժ���������֣���ľ���죬Ũ�����̣��м�һ��ʯ����
���ӵ��ţ�������һ�ž�����Ϊ��Ȫ������˵��ǰ����ʦ��������ʦ��ּ��
������Ժ��ǽ������һ��ʯ������������Ѿã�������ּ��Ѿ���������ˣ�Ժ
�ﻹ����һ�þ����㣬�֦���ɣ�Ҷï��ʢ����ʱ����һ���󵭵������㡣
LONG);
        set("exits",
        ([
          "south" : __DIR__"shanmen",
          "north" : __DIR__"zhaohe_tang",
        ]));
        set("need_clean", "�����");
        set("outdoors","kongdong");
        create_door("south","����ľ��","north",DOOR_CLOSED);
        set("objects",([
                __DIR__"npc/ke" : 2,
                __DIR__"npc/zl1" : 1,
                	__DIR__"npc/zl2" : 1,
                		__DIR__"npc/zl3" : 1,
                			__DIR__"npc/zl4" : 1,
                				__DIR__"npc/zl5" : 1,	
                ]) );
        setup();
 
}
