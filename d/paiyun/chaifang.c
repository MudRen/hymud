// Room: /d/paiyun/chaifang.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
һ��СС�Ĳ񷿶����˸ɵĲ�𣬲����ŵĺ����룬����
�Ӱ�ȫ�Ƕȿ����ﻹ�Ǻ�Σ�յģ���������������һ�ѻ�fanghuo)
�ٺ��ǿ���˵����ʲô�����
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu2",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
