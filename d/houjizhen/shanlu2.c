// shanlu2.c
//by dicky

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
������һ�����Ѷ��ϵ�ɽ��С·�ϣ�����ʮ�ֻ�����ǰ�治Զ������
һЩС���֣���������С·ͨ���������
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"southdown" : __DIR__"shanlu1",
		"northwest" : __DIR__"shanlu4",
		"east" : __DIR__"shanlu3",
	]));
	setup();
	replace_program(ROOM);
}

