//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","ի��");
	set("long",@LONG
�������ի�ã�����ἵ��Ӻͽ�������ŵĵط�������һ������ʱ�õĳ���
��������������Լ���ߣ���ˮ���겻�ݣ��ݴ�����ˮ���Գ��������Ҫ��һ��
�ƽ�����������һ��ˮ��ի�õ�һ���������ڴ������С��ʿ���ջ�æ��
��ի������һ�Ƿ�������زˣ�����ἵ�����ɽ���Լ��ֵġ�
LONG);
	set("exits",
	([
          "east" : __DIR__"zhaohe_tang",
          	]));
//        set("outdoors","kongdong");
set("need_clean", "�����");


	set("objects",([
		__DIR__"npc/kdizi5" : 1,
                __DIR__"npc/kdizi3" : 2,
		__DIR__"npc/obj/subing" : 3 ,
		__DIR__"npc/obj/hulu" : 2 ,
		]) );
        setup();
        //place_program(ROOM);
}
