// Room: /d/fengtian/bingqi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ԭ����һ�������̣���������սʱΪ���Ӵ����˺ܶ����
���͸ɴ����˱����̣����������ҵ����������ǿ��Ը����
������ĵط���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ll3",
]));

	set("objects",([
	__DIR__"npc/weaponboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
