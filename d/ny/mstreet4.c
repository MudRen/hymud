
// Room: /d/snow/mstreet4.c

inherit ROOM;

void create()
{
    set("coor",({-100,4770,10}));
	set("short", "��Զ������");
	set("long",
"������Զ�����ߵĴ�֣�һ����ȥ�Ǳ�ֱ����Զ�ֵ�ͨ�����ߣ�������һ�Ҵ������ӣ�����\n"
"��������������Զ�������õ����ֵ�������һֱͨ�����⡣������Լ����������ӣ��Ƕ���\n"
"һЩ���ռҵĺ�ͯ����ʶ�ֵĵط���\n"
);
	set("exits", ([ /* sizeof() == 3 */
  "east"  : __DIR__"mstreet3",
  "north" : __DIR__"smithy",
  "south" : __DIR__"school",
  "northwest" : __DIR__"nroad7",
]));
	set("no_clean_up", 0);
        set("objects", ([
              __DIR__"npc/scavenger": 2 ]) );

	setup();
}
