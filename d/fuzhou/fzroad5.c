// Room: /d/fuzhou/fzroad5.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "���ӹŵ�");
	set("long", @LONG
����������������ɽ�������������Ĺ���̣����ղ�����⡣
ɽ�ж������޳�û�޳�����·������·����һ���Ẻ����������
���ۿ����㡣
LONG );
	set("exits", ([
		"westup"    : __DIR__"fzroad6",
		"northeast" : __DIR__"fzroad4",
		"north" : "/d/jinyong/book8/fuzhou/fzroad5",
	]));
        set("objects", ([
		"/d/qingcheng/npc/fang" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
//	replace_program(ROOM);
}


int valid_leave(object me, string dir)
{
        if ( !me->query_temp("jinyong/book8/biaoju_ask") && dir == "north" )
        	return notify_fail("���潭����ʿѰ�����ȥ��������\n");
        return ::valid_leave(me, dir);
}