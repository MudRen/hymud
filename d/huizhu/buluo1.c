// Room: /d/huizhu/buluo1
inherit ROOM;

void create()
{
  set ("short", "���岿��");
  set ("long", @LONG
�˴����������֣�һ��б��ֱ�������ԭ�������ڴ����ڼ���������
֮�䣬���ߵ�һ���������ر�Ĵ�һ�㡣�ϱ�����С·ͨ������֮�С�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zhangpeng",
  "west" : __DIR__"zhangpeng1",
  "north" : __DIR__"buluo2",
  "south" : __DIR__"buluo",
]));

        set("objects", ([
                __DIR__"npc/qingbing" : 2,
                __DIR__"npc/qingbing2" : 1,
        ]));

  set("outdoors", "huizhu");
  setup();
  //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( objectp(present("qing bing", environment(me))) && 
		dir == "west")
		return notify_fail("�����ס�����ȥ·��\n");


	if ( objectp(present("qing bing", environment(me))) && 
		dir == "east")
		return notify_fail("�����ס�����ȥ·��\n");


	return ::valid_leave(me, dir);
}
                                                                                                                                                            