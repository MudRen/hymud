// Room: /d/jinghai/jhd15.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
������һ�������ͥԺ������Ĳݵ��Ϸ��������ִ��ľ׮��
��һ����һ���������ӣ�ʮ�˰����Ӧ�о��У�������ƽʱ����
����������ָ�����ɵ�һЩ�߼�ͷĿ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"jhd16",
  "east" : __DIR__"jhd12",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
