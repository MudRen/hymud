// Room: /d/menggu/road2
inherit ROOM;

void create()
{
  set ("short", "Ӫ�ʼ�");
  set ("long", @LONG
��Ŀ����,�Ƕ������������Ӫ��,һ������һ��,�ɹŲ�������Ϊ��,
ƽʱ��ס�����ɹŰ�,��ⷽ��.�ϱ�������Ӫ,�����Ӫ��ǰ˩�˼�����Ȯ
�����Ӫ���������ס��.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road1",
  "east" : __DIR__"shuchi",
  "north" : __DIR__"chahe",
  "south" : __DIR__"qingwei",
]));

	set("objects", ([
		__DIR__"npc/bing"   : 4,
	]));
  set("outdoors", "menggu");
  setup();
  //replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("menggu bing", environment(me))) && 
		dir == "north")
		return notify_fail("�ɹű���ס�����ȥ·��\n");
	if ( objectp(present("menggu bing", environment(me))) && 
		dir == "east")
		return notify_fail("�ɹű���ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}                                                                                                                                                                                                                                                                                                                                     