// shilu4.c
// by dicky

inherit ROOM;

void create()
{
       set("short", "��ʯ·");
	set("long", @LONG
����һ����ʯ·��·�������ʯ���̳ɵģ��̵��������룬
��·�ɶ�������һֱͨ����ľ�ͷ��������һ�Ҳ�ݣ����
ǰ��Ļ����ڷ���������ҡ�ڡ�
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ 
	    "west" : __DIR__"shilu5",
	    "north" : __DIR__"jiuguan",
	    "east" : __DIR__"shilu3",
	]));

	setup();
	replace_program(ROOM);
}
