// Room: /u/lots/d/boyroom.c
// LOTS 1998/10/20

inherit ROOM;

void create()
{
	set("short", "�����ӵ�ס��");
	set("long", @LONG
�����ǰ����ӵ�ס��,���ڴ�С���ܸ��׵�Ѭ��,���������ڼ��ϰ��.
��Χֻ��һЩ�Ŷ�,�����İ����ķ��ı�������,��һ��ľ��.
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"west" : __DIR__"houhuayuan",
	]));

	set("objects", ([
		"/d/kaifeng/npc/boy" : 1,
	]));

	setup();
	replace_program(ROOM);
}
