// Room: /d/fengtian/jjf4.c

inherit ROOM;

void create()
{
	set("short", "�쾮");
	set("long", @LONG
�ƹ������������͵��˻ʵ۸����쾮���쾮������Ǹ���
���ţ�СС���쾮�����˲��ٻ��ݣ�����һ������ͨ�ĵĸо���
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lian",
  "west" : __DIR__"jjf3",
  "east" : __DIR__"jjf5",
]));
        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
