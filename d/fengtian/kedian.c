// Room: /d/fengtian/kedian.c

inherit ROOM;

void create()
{
	set("short", "�м�͵�");
	set("long", @LONG
�������ʢ���������Ŀ�ջ������ʢ���ش�Ҫ�����ټ�����
��۸���ˡ������ܵ���������ʵ�����ſڹ���һ��ľ��(pai)��
LONG
	);

	set("item_desc", ([
		"pai" : "¥�Ͽͷ���ÿ��һ��������\n",
	]));
        

	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"kd4",
	"up"   : __DIR__"kezhan2",
]));
	set("objects", ([
		__DIR__"npc/waiter" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��С��������ס��˵�������ϻ�û��С�ĵ�Ǯ�ء�\n");
	if( me->query_temp("on_rided") && dir == "up")
		return notify_fail("��С������¥��ǰ˵�������ϵ����ﻹ������¥�°ɡ�\n");

	if ( me->query_temp("rent_paid") && dir == "north" )
		me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
