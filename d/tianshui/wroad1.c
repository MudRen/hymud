// Room: /d/tianshui/wroad1.c

inherit ROOM;

void create()
{
	set("short", "С������");
	set("long", @LONG
��ʯ�ֵ�������ͷ���죬����·�Ƚ�Ƨ����ƽʱҲ������
������������С��ѧ�ã���Լ�������ʵĶ��������������򳤵�
�ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wroad2",
  "north" : __DIR__"school",
  "east" : __DIR__"cross",
]));
	set("objects",([
	__DIR__"npc/whet_man" :1,
]));

	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
