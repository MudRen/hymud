// Room: /u/qingyun/jyzj/conglin2.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "ѩɽ����");
	set("long", @LONG
����һ���ܴ�Ĵ��֣���ľ��֦Ҷ�Ϲ����˱�ѩ��ѩ�׵�һ��Ƭ��������
�ȡ�������ɽ�����죬ֱ��ɽ�����ڴ�����΢¶��һ��С������ϡ���ϣ�����
��С���ϣ�ѩ��������һ�г�������ӡ��
LONG	);
	set("exits", ([
		"westup" : __DIR__"xuanya",
		"southdown" : __DIR__"conglin1",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("objects",([
		__DIR__"npc/dog1" : 1,
		__DIR__"npc/dog2" : 1,
		__DIR__"npc/dog3" : 1,
		__DIR__"npc/dog4" : 1,
	]));
	setup();
	//replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
object fang;
object who;
int i;
who=me;



	if ( objectp(present("dog", environment(me))) )
		return notify_fail("һֻ����ס�����ȥ·��\n");



        return ::valid_leave(me, dir);
}
