// Room: /d/lumaji/lu16.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ܵ���ľ�����дУ�һ�ۿ������ߡ����������˼�����ȴ
��Щ�Ҳ�������ĸо������ɵ������˳������ּ�ݵ�����һЩ
ɢ�����֦�������������µġ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"lu15",
	"east" : __DIR__"pomiao",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
