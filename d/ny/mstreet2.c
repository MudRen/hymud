
// Room: /d/snow/mstreet2.c

inherit ROOM;

void create()
{
        set("coor",({-50,4770,10}));
	set("short", "��Զ�ǽֵ�");
        set("long",
"����������Զ�ǵĴ�֣������߲�Զ������Զ�ǵ����Ĺ㳡������ı�����һ���ģ��С��\n"
"Ǯׯ����������ʹ����ȥ������˵��������ʲô�ö������ء�\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"bank",
//  "south" : "/d/snow/mstreet1",
  "east" : __DIR__"mstreet1",
  "west" : __DIR__"mstreet3",
]));
        set("objects", ([
              __DIR__"npc/scavenger": 2 ]) );

        set("outdoors", "ny");

        setup();
        replace_program(ROOM);
}
