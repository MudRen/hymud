// Room: /u/xiaozhen/linlu2.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������һƬ�ž���С���֣�һ��΢�紵������Ҷɳɳ�����졣
������һ������С·��·�ߵĵ��ϲ�������Ҷ������������С·
�Ǿ��������ߡ�ǰ����һ�����¡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"linlu3",
  "southwest" : __DIR__"linlu1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
