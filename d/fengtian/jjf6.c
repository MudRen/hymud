// Room: /d/fengtian/jjf6.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�ʵ۸��ĺ�԰�ܴ󣬻�԰�ﻹ��һ��С�ĺ���������̨¥
��޵�ʮ�ֱ��£������������԰ʮ��������
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jjf5",
]));
        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
