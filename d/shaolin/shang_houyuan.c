inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�������̼ұ��ĺ�Ժ����Ժ��������������ȫ������ɳʯ
�������ϱ���һ����ľ�����ȣ�ͨ���������ڡ���߲�ʱ������
���˱ǵķ����㣬ԭ�������ǳ������ڡ�
LONG);
	set("exits", ([
		"north"  : __DIR__"shang_lianwun",
		"south"  : __DIR__"shang_zoulang2",
		"east"  : __DIR__"shang_huating",
		"west"  : __DIR__"shang_chufang",
	]));
        set("objects", ([
                __DIR__"npc/tai" : 1,
                __DIR__"npc/shang2" : 4,
        ]));
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( objectp(present("shang laotai", environment(me))) && 
		dir == "north")
		return notify_fail("����̫��ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}
