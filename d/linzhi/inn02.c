// Room: /d/linzhi/inn02.c

inherit ROOM;

void create()
{
	set("short", "����Ȧ");
	set("long", @LONG
�����ǿ͵�����ڵĵط�������Χ������һȺ���򣬱���ľ
׮��˨�ż�ͷţ���Ա�Χ������һЩ����ʲô�ġ����п��˵�ʲ
ô�⣬����Ǿ���������ץ���ס�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"inn",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
