//Edited by fandog, 01/31/2000
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG
����һ�����������ȡ�����������֪�����˵��鷿�����߾�ͷ��һ
�䷿����������һƥ���������Ǹ����á��ϱ��Ƕ��᷿����֪�����˺�
�Ҿ�ס�ĵط�����������û�µ���������һ��Ѿ�ߵ�Ц�š�
LONG);
	set("objects", ([
		"/d/city/npc/yayi"   : 3,
		__DIR__"npc/yahuan1" : 1, 
	]));
	set("exits", ([
		"west"  : __DIR__"shufang",
		"east"  : __DIR__"lingtang",
		"south" : __DIR__"dongxiang",
		"north" : __DIR__"huayuannew",
	]));
  
	set("coor/x", -1480);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	//replace_program(ROOM);
}
void init()
{
	add_action("do_biqi", "biqi");
	add_action("do_biqi", "bingqi");
}

int do_biqi()
{
	object me = this_player();
	if (!me->query_temp("jinboxunhua"))
		return 0;
	me->set_temp("biqi", 1);
	message_vision(HIG"$N����һ��������ס�˺�����\n"NOR, me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "south")
		me->delete_temp("biqi");
	return ::valid_leave(me, dir);
}