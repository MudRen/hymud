// Room: /d/linzhi/lin25.c

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
  "northeast" : __DIR__"lin24",
  "southwest" : __DIR__"lin26",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4800);
	setup();
	replace_program(ROOM);
}
