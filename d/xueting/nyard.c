// Room: /d/snow/nyard.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
������һ��������൱Ǭ�����鷿����ľ����������������
�Ե�ʮ�ֿ��������������һ����ܣ��������һ���ŵ��߶����飬
�����߳����ſ��Կ����쾮��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"inneryard",
]));

//	set("objects", ([
//		__DIR__"npc/girl":1 ]) );

//	setup();
	replace_program(ROOM);
}
