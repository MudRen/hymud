// Room: /d/fengtian/jjf1.c

inherit ROOM;

void create()
{
	set("short", "���ʹ�����");
	set("long", @LONG
����Ĵ����������ɶ�ߣ��ſ������������ʯʨ�ӣ�����
��צ������һ��������顰���ʹ����������֣��ſڵ�ʯ
�״�ɨ�ĸɸɾ�����������Ǵ��ʵ۵ĸ��ڡ�
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wy6",
  "east" : __DIR__"jjf2",
]));

        set("objects",([
        	__DIR__"npc/bing" :1,        
        	__DIR__"npc/bing2" :3,        	
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
	return ::valid_leave(me, dir);
}

