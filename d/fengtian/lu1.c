// Room: /d/fengtian/lu1.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
���»�·�ڹս�����С�����ĳ����������˺ܶ࣬����
���ߺܰ�����Ҳ����Ҫע�ⰲȫ��
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu2",
  "east" : __DIR__"xh3",
  "north" : __DIR__"zhai3",
]));

	set("objects",([
"/clone/npc/man" : 1,
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
