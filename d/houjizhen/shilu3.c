// shilu3.c
// by dicky

inherit ROOM;

void create()
{
       set("short", "��ʯ·");
	set("long", @LONG
����һ����ʯ·��·�������ʯ���̳ɵģ��̵��������룬
��·�ɶ�������һֱͨ����ľ�ͷ���ϱ���һ�ұ����̣�
������һ�����СԺ��·�ϼ���û��ʲô���ˡ�
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ 
	    "west" : __DIR__"shilu4",
	    "south" : __DIR__"bingqipu",
	    "north" : __DIR__"minju",
	    "east" : __DIR__"shilu2",
	]));

	setup();
	replace_program(ROOM);
}
