// Room: /d/canyon/canyon7.c

inherit ROOM;

void create()
{
	set("coor",({-300,4100,0}));
	set("short", "���Źعȵ�");
	set("long",
"���Ź����������£��м��ǹȵأ���״�������յ�˫�壬�ɴ˵�������������վ�������ͨ\n"
"����ʦ�����Ͼ������������ˣ������Ǳ��ұ���֮�ء�\n"
);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"shance",
  		"north" : __DIR__"canyon6",
]));

        set("outdoors","yanmen");
	setup();
	replace_program(ROOM);
}