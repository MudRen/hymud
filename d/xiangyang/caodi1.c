// Room: /d/xiangyang/caodi1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������������Ĳݵء��ɹű���������������İ���ȫ��
���ˣ��ɹű��۳���ȥ����Ϊ��������������������š�
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"west"  : __DIR__"northgate2",
		"up"  : __DIR__"gaotai",
	]));
	set("objects", ([
		"quest/guojob/badjob/mengge"   : 1,
		__DIR__"npc/tuolei"   : 1,
		__DIR__"npc/menggubing" : 4,
	]));
	
	set("roomif","$botten#�������|��������:ask meng ge about job|ask meng ge about fangqi$#");
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( objectp(present("menggu bing", environment(me))) && 
		dir == "up")
		return notify_fail("�ɹű���ס�����ȥ·��\n");

	if ( objectp(present("tuo lei", environment(me))) && 
		dir == "up")
		return notify_fail("�ɹ����ϴ�Ԫʦ��ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}