//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","������");
	set("long",@LONG
�ڡ����ƹ�־���������������¡����������������ѹ����֮����δ���
���Ѷᡱ���������µı����С�������ۡ���ʯ�̣���ǰһ��ʯ�������գ�����
Ҳ���˽������³�Ϊ�����շ塱�����¸ߴ���һ��С���裬��������������Χ
�������ģ�ʵ�ǵ���Ʒ��˵�����������ɵľ���֮����
LONG);
	set("exits",
	([
          "west" : __DIR__"zixiao",
          "east" : __DIR__"qipan_ling",
          	]));
        set("outdoors","kongdong");
	set("objects", ([
		__DIR__"npc/o_yizhe" : 1,
		__DIR__"obj/qipan" : 1,
		__DIR__"npc/y_yizhe" : 1,
		]) );
        setup();
        //place_program(ROOM);
}
