//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","��ʸ�");
	set("long",@LONG
��ʸ�����ɽ�ߣ������ɽ��ߵĽ�������Ϊ���۶����������þ�ʯ����
�쳣�ι̣��ڿ���ɽ�ߵĵط���һ���ʯ�飬����ƽ̹������ʯ��ʯ�գ���Χ��
��ʯ�����ഫ��ʱ������������ܼ��ڴˣ�·����һ��ʯ������һԫʯ֮�ϣ���
���з���֮�С�����һ����̻Ի͵���¥�����������е������У����ڳ�������
�֣���Ʈ��֮���Ϲ��ڣ���Ϊ��ۡ�
LONG);
	set("exits",
	([
	"east" : __DIR__"xuanyuan_gong",
          	]));
        set("outdoors","kongdong");
	set("objects", ([
		__DIR__"npc/kdizi1" : 2,
		]) );
        setup();
        //place_program(ROOM);
}
