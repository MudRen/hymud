// Room: /d/paiyun/mingzhai2.c

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
  "west" : __DIR__"lu8",
]));
set("objects", ([
	"/clone/money/gold":1,
	"/clone/money/silver":5,	
	"/d/qianjin/npc/funu":2,		
       ]) );
	setup();
	replace_program(ROOM);
}
