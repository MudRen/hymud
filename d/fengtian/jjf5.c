// Room: /d/fengtian/jjf5.c

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
����쾮�ͽ��˺��᷿�����᷿�ǻʵ�����լԺ����֮����
�ڣ����˺���Ҳ�����ں��᷿һ�����죬����Ӧ���Ǽ�ͥ�ľۻ�
���������Եú���ů��
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"shu",
  "west" : __DIR__"jjf4",
  "east" : __DIR__"jjf6",
  "north" : __DIR__"wo",
]));

	setup();
	replace_program(ROOM);
}
