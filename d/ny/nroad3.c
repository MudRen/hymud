
inherit ROOM;

void create()
{
	set("coor",({0,4650,10}));
	set("short", "����С��");
	set("long",
"��������վ��һ������С����ɽ����������Զ�ǽֵ���������һ��ɽ·�����ﱾ����һ����\n"
"�ٵ��г���������Ϊս���ĵĳ�����ܶ�ĸ��������Ʋ������յ����־Ͳ������ˡ�\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nroad6",
        "north" : __DIR__"sroad1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/farmer" : 2,
]));
        set("outdoors", "ny");

	setup();
}
