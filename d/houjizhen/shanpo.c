// shanpo.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "Сɽ��");
	set("long", @LONG
������һ���˼�������Сɽ���ϣ��������ִ�����·��ʱ��ʱ�֣�
ɽ����棬���������������Ŀ�����������ǰ��һ��ɽ��С·��һֱ��
ǰ���졣
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"northdown" : __DIR__"shanlu1",
	        "southdown" : __DIR__"shigang",
	]));

	setup();
	replace_program(ROOM);
}


