//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","������");
	set("long",@LONG
��������������֮��Ψһ��ͨ�������������š���ǰ����ʯ��⻬�����ľ�
���������һ��һ�����ʯ�ѻ�ǳխ��ʯ����һֱͨ���±ڵļ���ʯ����������
��������塱����������Ů��������עĿ����̣���ʱ���˾������������У���
ν�������ס������Ͼ��ǡ�����·���ˡ�
LONG);
	set("exits",
	([
          "east" : __DIR__"lianhua_tai",
          "up" : __DIR__"yiwu_lu",
          	]));
        set("outdoors","kongdong");
        setup();
        //place_program(ROOM);
}
