// Room: /d/fengtian/du.c

inherit ROOM;

void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
���������������÷�����Ȼ���ﵱ�ҵĺ����ſ�ջ���ϰ彻
���������ĵĻ������Ǹ���ȥ�����㿴�ſڵ��˽���������
������˸��ǻ���ڵأ��öĵ������������һ������ů�ĸо���

LONG
);



	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ll1",
]));

	set("objects",([
	__DIR__"npc/judge" : 1,
]));

	setup();
}
