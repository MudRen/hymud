
// Room: /d/snow/yamen_square.c

inherit ROOM;

void create()
{
	set("coor",({-40,4850,10}));
	set("short", "����ǰ�Ĺ㳡");
	set("long",
"����������ǰ�Ĺ㳡���������������������ǳ����֣��������˽����š���ʱ��һ��������\n"
"�������У��þ����Ŀ��ɨ������Χ��������������ȥ���������ˣ���������վ��\n"
);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"postoffice",
    "northwest" : __DIR__"yamen_gate",
  "north" : __DIR__ "nroad4",
]));
	set("objects", ([ /* sizeof() == 6 */
 // __DIR__"npc/butcher" : 1,
  __DIR__"npc/playboy" : 2,
  __DIR__"npc/seller" : 1,
  __DIR__"npc/pgirl" : 1, 
]));
        set("outdoors", "ny");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
