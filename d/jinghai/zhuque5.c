// Room: /d/jinghai/zhuque5.c

inherit ROOM;

void create()
{
	set("short", "��·��");
	set("long", @LONG
������һ������·�ڡ�ӭ�洵��һ�����̵���ζ�������뺣
�߲�Զ�ˡ��������Ǻ�����Լ�������������������Ͼ����в�С
һ��ׯԺ��������һ����Ţ��С·��
LONG
	);
	set("outdoors", "jinghai");
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"bank1",
  "southeast" : __DIR__"zhuque2",
  "south" : __DIR__"zhuque1",
  "north" : "/d/zuojiacun/lu19",
]));

	setup();
	replace_program(ROOM);
}
