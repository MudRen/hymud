// shanlu1.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
������һ�����Ѷ��ϵ�ɽ��С·�ϣ�����ʮ�ֻ�����ż����������������
����Ĳ��ɵı����ˡ�
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"southup" : __DIR__"shanpo",
	        "northup" : __DIR__"shanlu2",
	        "westup" : __DIR__"songlin2",
	]));

	setup();
	replace_program(ROOM);
}

