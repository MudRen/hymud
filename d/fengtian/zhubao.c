// Room: /d/fengtian/zhubao.c

inherit ROOM;

void create()
{
	set("short", "�鱦��");
	set("long", @LONG
ʢ������鱦����ʢ���Ǹ����ǹ��ٵĳ���������鱦���
��ʯ����Ի���۸߶����ƣ��������������е��ɶ����񣬶���
��ɫ����������һ��Ҫ��һ�顣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xm4",
]));

	setup();
	replace_program(ROOM);
}
