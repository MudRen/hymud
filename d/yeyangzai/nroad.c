// Room: /d/yeyangzai/nroad.c

inherit ROOM;

void create()
{
	set("short","��ЧС·");
	set("long", @LONG
����һ��ĸ���������ʲô�ˡ���˵�������±��ϵıؾ�֮·����ô̫
ƽ������С��Ϊ�������������֮·�������Ӳݴ������ƺ�Ҳ������
֮·������֪Ϊ�������˼���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"caocong",
  "south" : __DIR__"huangye",
]));
	set("outdoors","Ұ��կ");

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir=="south") me->set_temp("where_to","south");
	return ::valid_leave(me,dir);
}
