// Room: /d/fengtian/lu2.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
���»�·�ڹս�����С�����ĳ����������˺ܶ࣬����
���ߺܰ�����Ҳ����Ҫע�ⰲȫ.
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dayuan",
  "south" : __DIR__"zhai4",
  "east" : __DIR__"lu1",
]));


        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
