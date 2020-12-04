// Room: /d/fengtian/quest2.c

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
��������ɽ���Ƶ�һ�鳤����ݵĲݵأ��ݵ������ǳ��ŵ�
����С���Ϲ��ż�����ʴ���Ƶ��������������ס�����˲���һ
����ɭ�ֲ��ĸо�������ɽ������һ��С������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"quest1",
  "enter" : __DIR__"quest3",
]));

	//

	set("objects",([
	__DIR__"npc/laozhe" : 1,
]));

	setup();
}

int valid_leave(object me,string dir)
{
	object ob;

	if( userp(me)
	&& (dir == "enter")
	&& objectp(ob = present("old man",this_object())) )
	{
		if(!me->query_temp("feiyu_upgrade_quest/ask_oldman"))
			return notify_fail(sprintf("%s��ס���ʵ�������������ʲô�����𣿡�\n",ob->name()));
		ob->set_leader(me);
		return 1;
	}
	return ::valid_leave(me,dir);
}
