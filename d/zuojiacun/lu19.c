// Room: /d/zuojiacun/lu19.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����Ţ��С·�����ڸ��¹����꣬ǰ��ĵ�·�ѱ���
���ˡ�·�Ķ�����һ��ס����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
	"west" : "/d/tieflag/cape",
	"east" : __DIR__"xiaojuan",
	"north" : __DIR__"lu18",
	"south" : "/d/jinghai/zhuque5",
]));
        set("objects", ([
"quest/skills2/wunon/yu/yutan" : 5,
        ]) );

	set("outdoors", "zuojiacun");
	setup();

	replace_program(ROOM);
}
