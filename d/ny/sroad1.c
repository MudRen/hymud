
// Room: /d/snow/sroad1.c

inherit ROOM;

void create()
{
        set("coor",({0,4700,10}));
	set("short", "��Զ�ǽֵ�");
        set("long",
"������Զ�ǵĽֵ���������һ�����ֵĹ㳡���ϱ�����С·ͨ�������£���������һ��С��\n"
"����ɽ��ͨ��ɽ�ϣ�������һ���Ƚ�խ�Ľֵ����β�������֮�䴫������Ȯ�͡�\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hockshop",
  "north" : __DIR__"square",
  "south" : __DIR__"nroad3",
//  "south" : "/d/snow/tao",
  "east" : __DIR__"machang",
]));
        set("outdoors", "ny");

        setup();
        replace_program(ROOM);
}
