// Room: /d/xiaozhen/biaoju3.c

#include <room.h>

inherit ROOM;


void setup();

void create()
{
	set("short", "����");
	set("long", @LONG
�������ھֵ����ң������ڻ�û���ü����ߵĻ��ﶼ�ȴ��
�����������һ�����š�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"biaoju2",
]));
	set("objects",([
	__DIR__"obj/tie_xiang" : 3,
]));

if (random(30)==0)
	{
	set("objects",([
		__DIR__"obj/sword_and_qiao" : 1,
		__DIR__"obj/letter" : 1,
	__DIR__"obj/tie_xiang" : 3,
]));

	}
	setup();

}

