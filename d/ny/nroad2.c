
// Room: /d/snow/eroad1.c

inherit ROOM;

void create()
{
    set("coor",({0,4850,10}));
	set("short", "��վС��");
	set("long",
"��������ʯ�ٵ������оͿ��Ե�����Զ�����š�������һ��ʯ��·����������ȥ��Զ�ǵ���\n"
"�Ĺ㳡��\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nroad1",
  "west" : __DIR__"postoffice",
  "north" : __DIR__"crossroad",
]));
	set("no_clean_up",0);
	set("outdoors", "ny");
//    set("objects",());
	setup();
	replace_program(ROOM);
}
