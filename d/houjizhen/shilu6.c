// shilu6.c
// by dicky

inherit ROOM;

void create()
{
       set("short", "��ʯ·");
	set("long", @LONG
����һ����ʯ·��·�������ʯ���̳ɵģ��̵��������룬
��·�ɶ�������һֱͨ����ľ�ͷ���ϱ߾�����վ��������
����������Ϣ������
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ 
	    "west" : __DIR__"muqiao",
	    "south" : __DIR__"yizhan",
	    "east" : __DIR__"shilu5",
	]));

	setup();
	replace_program(ROOM);
}
