// Room: /d/zuojiacun/zahuo.c

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��С�ӻ��꣬���ڿ������ߣ���˵������һ��Ķ�
������һЩ�����õ�ҩʲô�ġ���������һ����ͷ���ڴ������
��Ե��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu4",
]));
  	set("objects",([
	"/d/cloud/npc/seller" : 1,
]));
	setup();
	replace_program(ROOM);
}
