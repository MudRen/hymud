// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "С¥");
	set("long", @LONG
����һ�����µ�С¥�����ߵ�������ɵ���ǰһҫ������
�ŵ�һ�����ĵ�������
LONG
	);
	set("exits", ([ 
            "west" : __DIR__"huating1",
	]));
        set("objects", ([
		"/d/shiliang/npc/yuanchenzhi" : 1,
	]));
	set("coor/x", 1620);
	set("coor/y", -1770);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}