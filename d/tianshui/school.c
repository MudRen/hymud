// Room: /d/tianshui/school.c

inherit ROOM;

void create()
{
	set("short", "С��ѧ��");
	set("long", @LONG
ѧ�÷ǳ���ª������Ҳ�Ѿ��ƾɣ�����ɨ�úܸɾ���һλ��
��������վ��ǰ��ҡͷ���Եش���ѧ�������顣ӭ��ǽ�Ϲ���һ
��ɽˮ�����Ա���һ�����顣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wroad1",
]));

	set("objects",([
	__DIR__"npc/teacher" : 1,
]));
	setup();
}

int valid_leave(object ob,string dir)
{
	if(ob->query_temp("school/����Ң"))
		ob->delete_temp("school/����Ң");
	return ::valid_leave(ob,dir);
}