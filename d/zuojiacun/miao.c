// Room: /d/zuojiacun/miao.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��С������������������ǰ��Ҫ�����������ݡ�
�㰸�ϰڷ���һ����¯������Ʈ�����������̡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu9",
]));
  	set("objects",([
	"/clone/npc/man" : 2,
]));
	set("valid_startroom",1);
	setup();
	replace_program(ROOM);
}
