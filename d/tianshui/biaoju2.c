// Room: /d/xiaozhen/biaoju2.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�ھ�����");
	set("long", @LONG
�����������ھֵ�������һ��̫ʦ�ΰ��������룬��������
������ͷ���ֳ��̴������ڱ�Ŀ��˼��ǽ�Ϲ��ż����ֻ���һ��
������������һ�����š�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"biaoju",
		"east" : __DIR__"biaoju3",
]));
	set("objects",([
	__DIR__"npc/ri_header" : 1,
]));
	setup();
}