// Room: /d/heifeng/cross.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ľ������ĵ��ţ�ɽ�紵�������һΣ���������֨
֨�¸µ����졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gate",
  "south" : __DIR__"lu10",
]));

	setup();
}
/*
int valid_leave(object me,string arg)
{
	if(arg == "n" || arg =="north")
		me->set_temp("heifeng/come_in",1);
	return 1;
}
*/
