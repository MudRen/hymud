
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "ɽ·");
	set("long",
"����һ���Ӳݴ�����С·���Ѷ���û���˴������߹���·��������Ϣ�ż�ֻ��ѻ����ʱ����\n"
"���������ë���Ȼ�Ľ�������ǰ��ȥ��Լ�ɼ�һ����ɽ��\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"happyinn1",
   "north" : __DIR__"bingying2",
  "westup": __DIR__"droad1",
]));
        set("no_npc",1);
	set("outdoors", "ny");
	setup();
//        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( !me->query("jinyong/book2") && 
		dir == "north")
		return notify_fail("һ�������ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}      