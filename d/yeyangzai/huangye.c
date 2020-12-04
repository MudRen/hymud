// Room: /open/stst/sazai/lu1.c

inherit ROOM;

void create()
{
	set("short","��Ұ");
        set("long", @LONG
	���ܹ�ͺͺ��һƬ������ɱ�����������������ʿ̸֮ɫ��ġ�
Ұ��կ���ˣ�û�¿ɱ�ȥ��Ѱ��·��

LONG

        );
        set("exits", ([ /* sizeof() == 2 */
		"north":__DIR__"nroad",
		"east":__DIR__"huanglu",
		"south":__DIR__"xiaolu",
]));
	set("area","Ұ��կ");
	set("outdoors", "yeyangzai");
	set("objects",([
		__DIR__"npc/sanzaizhu":1,
]));
        setup();
}
int valid_leave(object me,string dir)
{
	object ob;
	string banghui;
	object lp;
	mapping data;

	if( !userp(me))		return ::valid_leave(me,dir);
	if(! (ob=present("jia san",environment(me))))
		return ::valid_leave(me,dir);
	if(! living(ob))
		return ::valid_leave(me,dir);

	if(! mapp(data))	data=([]);
	if( data[query("area")])	{
		return ::valid_leave(me,dir);
	}
	if(me->query_temp("oldsix/can_leave"))	{
		me->delete_temp("oldsix/can_leave");
		return ::valid_leave(me,dir);
	}
	if(me->query_temp("where_to")=="south"&&dir=="south")	{
		message_vision("$N����һ�Σ�����$n��ǰ�����Ƚ�����·Ǯ��˵��\n",
		ob,me);
		return notify_fail("\n");
	}
	if(me->query_temp("where_to")=="north"&&dir=="north")	{
		message_vision("$N����һ�Σ�����$n��ǰ�����Ƚ�����·Ǯ��˵��\n",
		ob,me);
		return notify_fail("\n");
	}
	return ::valid_leave(me,dir);
}



