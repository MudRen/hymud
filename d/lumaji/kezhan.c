// Room: /d/lumaji/kezhan.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ��С��ջ�������˾��Ƕ���������˵��Ϊ����������
���Ƿ���ſ�����ҿ�ջ��ͨ��������������ж��������￴�ܣ�
����ֻ��һ������ڰ�������ſڵ�ľ��(pai)�϶��ǳ�����
LONG
	);
	set("item_desc", ([
		"pai" : "¥�ϸ߼䣬ÿ������������\n��С��΢���븶������\n",
	]));

	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"lu7",
	"up" : __DIR__"kezhan2",
]));

	set("valid_startroom",1);


	set("objects",([
		__DIR__"npc/waiter" : 1,
]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");
	if( me->query_temp("on_rided") && dir == "up")  // �ж��Ƿ���������
		return notify_fail("��С������¥��ǰ˵�������ϵ����ﻹ������¥�°ɡ�\n");

	return ::valid_leave(me, dir);
}

