// shilu2.c
// by dicky

inherit ROOM;

void create()
{
       set("short", "��ʯ·");
	set("long", @LONG
����һ����ʯ·��·�������ʯ���̳ɵģ��̵��������룬
��·�ɶ�������һֱͨ����ľ�ͷ���ϱ���һ���ӻ��̣�
·�ϼ���û��ʲô���ˡ�
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ 
	    "west" : __DIR__"shilu3",
	    "south" : __DIR__"zahuopu",
	    "east" : __DIR__"shilu1",
	    "north" : __DIR__"bank",
	]));

	setup();
	replace_program(ROOM);
}
