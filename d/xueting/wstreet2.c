// Room: /d/xueting/wstreet2.c

inherit ROOM;

void create()
{
	set("short", "ѩͤ�ֵ�");
	set("long", @LONG
������ѩͤ�����ߵĽֵ���������ѩͤ�����У��ƽʱ������
��һЩ���ϵĳ���������̸�����ϵ�ʱ�£��������й�ү�������
�£�Ҳ����������Ĺ��á�������������Զ�����ǳ���Ĺٵ�����
���ϱ���һ�Ҹ���̡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : __DIR__"court",
	//"west" : "/d/snow/sroad3",
	"east" : __DIR__"wstreet1",
]));
	set("objects", ([ /* sizeof() == 1 */
	//"/d/snow/npc/farmer" : 2,
	__DIR__"npc/dog":2,
	]));
	set("no_clean_up", 0);
	set("outdoors","xueting");
	setup();
	replace_program(ROOM);
}
