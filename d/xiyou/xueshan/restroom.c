//restroom.c

inherit ROOM;

void create ()
{
	set ("short", "��Ϣ��");
	set ("long", @LONG

������ѩɽ����ƽʱ��Ϣ�ĵط�����������һ�Ŵ�ʯ���������
��һЩˮ�����ġ����ϻ���������䡣���п��ϵ�һ�����Ϲ���
һ������(paizi)����ǽ�������߰����д�����֡�
LONG);

	set("item_desc", (["paizi" : "Ů�����Է��������Ͻ����ڡ�\n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"girlroom",
		"north" : __DIR__"boyroom",
		"east" : __DIR__"shanpo",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/misc/seat" : 2,
		"/d/obj/misc/table" : 1,
                "/d/xiyou/xueshan/npc/xunshi" : 2,
	]));

	set("valid_startroom", 1);

	set("outdoors", "xueshan");

	setup();


}


