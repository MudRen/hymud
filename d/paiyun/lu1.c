// Room: /d/paiyun/lu1.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��������կ��ɽ�ž�������������ȫ�ɶ���ʯ�̾͵�С·��
��������ʯ·��ԶԶ������Կ���һЩɽ�ߴ��Ľ�����ʯ·����
������կ��������һЩ������·�߻��ڡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"ta1",
  "south" : __DIR__"door",
  "east" : __DIR__"ta2",
  "north" : __DIR__"lu2",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
