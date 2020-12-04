// Room: /d/heifeng/corr08.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
���۵�С·��ɽ���ϣ���Χ����������֮�������һЩ����
ʱ�����ʯͷ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lin2",
  "south" : __DIR__"corr07",
  "north" : __DIR__"shanquan",
]));

	set("outdoors", "heifeng");

	set("objects",([
	__DIR__"npc/xunzhai" : 2,
	__DIR__"npc/toumu" : 1,
]));

	setup();
	replace_program(ROOM);
}
