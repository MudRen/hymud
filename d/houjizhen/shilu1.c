// shilu1.c
// by dicky

inherit ROOM;

void create()
{
       set("short", "��ʯ·");
	set("long", @LONG
����һ����ʯ·��·�������ʯ���̳ɵģ��̵��������룬
��·�ɶ�������һֱͨ����ľ�ͷ��·�ı�����һ�ҿ�ջ��
��ջǰ��������һ��ˣ��������һ���������õ����ƣ�����
����������ƶ�֮��ķ�϶���������ڵ������µ���ߣ���
������վ��һλŮ�����ر������עĿ��
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ 
	    "west" : __DIR__"shilu2",
	    "north" : __DIR__"kedian",
	    "south" : __DIR__"majiu",
	    "east" : __DIR__"paifang",
	]));

	set("objects",([
		__DIR__"npc/gunv" : 1,
	]));

	setup();
	replace_program(ROOM);
}
