// Room: /d/paiyun/mingzhai1.c

inherit ROOM;

void create()
{
	set("short", "ľ�巿");
	set("long", @LONG
����һ��ԭľ��ɵĴ��ӣ�������ڷ��ż��Ŵ�ľ������
������ɽ��ƽʱ��Ϣ�ĵط���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu7",
]));
set("objects", ([
	__DIR__"npc/chick":1,		
       ]) );
	setup();
	replace_program(ROOM);
}
