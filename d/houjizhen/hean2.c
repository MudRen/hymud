// hean.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "�Ӱ�");
        set("long", @LONG
�����ǹ�ͺͺ�ĺӰ�������������������¶����ҷء�
LONG);

        set("outdoors", "houjizhen");

        set("exits", ([
		"north" : __DIR__"muqiao",
        ]));

	setup();
	replace_program(ROOM);
}
