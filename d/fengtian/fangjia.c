// Room: /d/fengtian/fangjia.c

inherit ROOM;

string go_enter(object me);

void create()
{
	set("short", "�����ּ�");
	set("long", @LONG
����һ����ͨ�Ĵ��߷������������ǳ��򵥣�ľ�����ϵ�
�����Ѿ����䣬�������ǳ��������������Ľ�ӡ������Ŀ��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"kd9",
	"west" : __DIR__"houyuan",
"enter" : __DIR__"quest1",
]));


	setup();
}


