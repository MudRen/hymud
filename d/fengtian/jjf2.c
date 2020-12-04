// Room: /d/fengtian/jjf2.c

inherit ROOM;

void create()
{
	set("short", "ͥԺ");
	set("long", @LONG
������ʹ���һ�����ķ����Ĵ�ͥԺ��ͥԺ�����кܶ��ֱ
�İ�������һ����ʯ�·��ɨ�ĸɸɾ���������ֱͨ�ʵ��й���
��������ͥԺ�ﻹ���˺ܶ໨���Եú���������
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jjf1",
  "east" : __DIR__"jjf3",
]));

        set("objects",([
        	__DIR__"npc/bing2" :2,        
        	__DIR__"npc/wujiang3" :1,        
       	
        ]));

        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	//replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("guan bing", environment(me))) && 
		dir == "east")
		return notify_fail("�ٱ���ס�����ȥ·��\n");

	if ( objectp(present("cao huachun", environment(me))) && 
		dir == "east")
		return notify_fail("�ܻ�����ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}

