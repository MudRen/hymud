inherit ROOM;

void create()
{
	set("short", "�̼ұ�����");
	set("long", @LONG
һ���޴��լԺӳ����������������������һ������ͭ��
�Ĵ��ţ������ǽ��ɸߵ�Χǽ�����ŵ��Ϸ�����һ���ң�����д
�š��̼ұ����������֡�
LONG);
	set("exits", ([
		"north"  : __DIR__"shang_qgc",
		"south"  : __DIR__"shang_road3",
	]));
        set("objects", ([
                __DIR__"npc/zhen" : 1,
                __DIR__"npc/shang2" : 3,
        ]));
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
	if ( objectp(present("shang baozhen", environment(me))) && 
		dir == "north")
		return notify_fail("�̱�����ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}