// Room: /d/fengtian/xunbu.c

inherit ROOM;

void create()
{
	set("short", "Ѳ��Ӫ");
	set("long", @LONG
ʢ��Ѳ��Ӫ���𼩲��ﷸ������Ѳ��Ӫ���������ֵ���Ѳ
��������ǽ�Ϲ���Ѳ���õ������Ϳ쵶��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guanlu3",
]));

	set("objects",([
		"/d/city/npc/xunbu" : 2,
]));

	setup();
	replace_program(ROOM);
}
