// Room: /d/xueting/wstreet1.c

inherit ROOM;

void create()
{
	set("short", "ѩͤ�ֵ�");
	set("long", @LONG
������ѩͤ��㳡���ߵĽֵ���������һ���ջ�����������
��û����ڡ��ϱ�һ�������ݣ��ſ���ɨ��ǬǬ���������Ǽ�˽��
ģ���������Ľֵ�ʮ�ֿ���·�ϻ��г�����ѹ�����Ĺ��ۡ�
LONG
	);
        set("outdoors", " xueting ");
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"school",
	"west"  : __DIR__"wstreet2",
	"east"  : __DIR__"guangchang_sw",
]));
	set("no_clean_up", 0);
	set("outdoors","xueting");

	setup();
	replace_program(ROOM);
}
