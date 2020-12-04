// Room: /city/kedian.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�͵�");
	set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ��������ţ���
������������������صķ������顣��С����������æ������ת���Ӵ�����ǻ
�����Ŀ��ˡ��͵�����˴Ӳ�¶�棬��������˭���и��ָ����Ĳ²⡣ǽ�Ϲ�
��һ������(paizi)��
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
//	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ��ʮ��������\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
"/clone/misc/dache" : 1,			
//		"clone/npc/paimaishi" : 1
"/d/npc/beichou" : 1,
	]));
	
set("roomif","$botten#��ս����|��Ա����|�����Ա|�����Ա|�鿴��|������|ס��|��������|�������:ask bei about challenge|ask bei about membergift|ask bei about membercards|buygoods <��Ʒ>|kan|qu <����>|give 50 silver to xiao er|ask beichou about job|ask beichou about ok$#");
	
	set("exits", ([
		"east" : __DIR__"majiu",
		"west" : __DIR__"beidajie1",
		"up"   : __DIR__"kedian2",
	]));

	setup();
	"/clone/board/kedian_b"->foo();
}

int valid_leave(object me, string dir)
{

	if ( userp(me) && !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

	if ( userp(me) && me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}