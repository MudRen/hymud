#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", "�̼ұ�����");
	set("long", @LONG
�������̼ұ��Ĵ����������ں��ǿ����������Ͽ���һ��
�޴�������ԡ��������Űڷ���һ�Ű�������һ��ѹ�����ã���
�ĸߴ���࣬���Ŷ��룬������Ϊ���࣬���ǡ����Ե����̽�����
LONG);
	set("exits", ([
		"north"  : __DIR__"shang_houting",
		"south"  : __DIR__"shang_xiaojin2",
		"east"  : __DIR__"shang_tinge",
		"west"  : __DIR__"shang_tingw",
	]));
        set("objects", ([
                __DIR__"npc/ming" : 1,
                __DIR__"npc/shang2" : 4,
        ]));
        
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();

}
int valid_leave(object me, string dir)
{
	if ( objectp(present("shang jianming", environment(me))) && 
		dir == "north")
		return notify_fail("�̽�����ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}


