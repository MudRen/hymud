// Room: /d/yeyangzai/xiaolu.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
���ܴ��ֻ��ƣ������巽���㲻�Ծ��üӿ��˲���������Щ�뿪�˵ء�
�����Ǹ���·�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"chalu",
  "west":__DIR__"caocong1",
  "north" : __DIR__"huangye",
]));
	set("outdoors", "yeyangzai");
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir=="north")me->set_temp("where_to","north");
	return ::valid_leave(me,dir);
}
