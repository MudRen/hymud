// shilu5.c
// by dicky

inherit ROOM;

void create()
{
       set("short", "��ʯ·");
	set("long", @LONG
����һ����ʯ·��·�������ʯ���̳ɵģ��̵��������룬
��·�ɶ�������һֱͨ����ľ�ͷ��������һ�����ã��ϱ�
��һ����ӣ�����������һ���յ�����С�
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ 
	    "west" : __DIR__"shilu6",
	    "north" : __DIR__"yaopu",
	    "south" : __DIR__"minju1",
	    "northwest" : __DIR__"xiaoxiang",
	    "east" : __DIR__"shilu4",
	]));

	set("objects", ([
		__DIR__"npc/seller" : 1,
	]));

	setup();
	replace_program(ROOM);
}
