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
          "east" : __DIR__"zixiao_ya",
          	]));
        set("outdoors","kongdong");
        setup();
        //place_program(ROOM);
}
