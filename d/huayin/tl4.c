// Room: /d/huayin/tl4.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����С��·��·�ϵ�������ѹ�ŵĳ��ޣ�·��û��
��������ڶ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"northeast" : __DIR__"tl3",
	"southwest" : "/d/zhongzhou/zhongzhoudu",
]));

	set("outdoors","huayin");
	setup();
	replace_program(ROOM);
}
