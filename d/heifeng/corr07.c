// Room: /d/heifeng/corr07.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
���۵�С·��ɽ���ϣ���Χ����������֮�������һЩ����
ʱ�����ʯͷ��
LONG
	);
	set("outdoors", "heifeng");

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lin1",
  "south" : __DIR__"corr06",
  "east" : __DIR__"shinv",
  "north" : __DIR__"corr08",
]));

	setup();
	replace_program(ROOM);
}
