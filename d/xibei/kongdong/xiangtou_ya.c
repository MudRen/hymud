//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","��ͷ��");
	set("long",@LONG
ӭ����һ��޴��ʯ�£���״������ͷ���˵����Ե�������ͷ�¡���ǰ���
ɽ������һ������������ɨ�㣬��ɨ���ɣ���֦�ɷ����ֽ�ǧͷ�ɣ�����������
һ���޴�Բʯ��ʯ������Ƕ��һ���������ߵ�������������֦�ɺ������֦����
���˽Գ�֮̽���ɡ�
LONG);
	set("exits",
	([
          "west" : __DIR__"juxian_qiao",
          "northup" : __DIR__"xuanhe_dong",
	]));
	set("outdoors","kongdong");
	set("objects", ([
		__DIR__"npc/kdizi2"  : 3,
		]) );
        setup();
        //place_program(ROOM);
}

int valid_leave(object me,string dir)
{
    if(dir=="northup")
      return notify_fail("�����Ƕ��£�û�����������ˡ�\n");
    return ::valid_leave(me,dir);
}
