//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","������");
	set("long",@LONG
�ഫ�������ǰ��ɾۻ�ĵط����ھ����ŵ����룬��һ�����׼�����ʯ̨��
�������գ���Χ�������ж��۴�ϸ��������������ʿ����������ٱ��Լ�������
��ÿ�괺��֮����������ڵǷ����󣬽�����ı�˺����Ƭ������̨�£��ɿ�
ɽ�ȼ�ǧ��ֻ����Ⱥ�����Σ�εΪ��ۡ�
LONG);
	set("exits",
	([
	"south" : __DIR__"shijie4",
	"east" : __DIR__"xiangtou_ya",
          "northup" : __DIR__"shanmen",
	]));
        set("outdoors","kongdong");
	set("objects", ([
		__DIR__"npc/youke" : 3,
		]) );
        setup();
        //place_program(ROOM);
}
