// Room: /d/linzhi/lin26.c

inherit ROOM;

void create()
{
	set("short", "������ɽ·");
	set("long", @LONG
������������ɽ�ı��࣬����ƽ��������4500�����ҡ�ɽ·
����˷�������ʮ�ֳ�������ʱ�з��������������Ҫ��ֹ��ǰ
���Ĳ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lin25",
  "westdown" : __DIR__"lin27",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
