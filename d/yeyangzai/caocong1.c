// Room: /d/yeyangzai/caocong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ݴ�");
	set("long", @LONG
�����ǰ��˶�ߵ��Ӳݴԣ����������зֲ��嶫��������ֻ����������
�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"east":__DIR__"nroad",
	"west":__DIR__"nroad",
	"south":__DIR__"nroad",
	"north":__DIR__"nroad",
]));
	set("outdoors", "yeyangzai");
	set("no_clean_up", 0);

	setup();
}


