//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","������");
	set("long",@LONG
������������䣬��λ�ʹ���ʦ�����ɽ��ɽ��·����ͨ��ͨ����߷��Ψ
һͨ���������ݡ���ɽ�����գ�ÿ�����꣬������������ɽ�ȣ������Ӧ��
��ɽ�����ѣ������ľ���ս���±�����������������Ħ����̣����С������ݡ�
����������֣���˵Ϊ��������ʡ�
LONG);
	set("exits",
	([
          "eastdown" : __DIR__"shijie2",
          "northup" : __DIR__"shijie3",
	]));
        set("outdoors","kongdong");
	set("objects", ([
		__DIR__"npc/youke" : 2,
		]) );
        setup();
        //place_program(ROOM);
}
