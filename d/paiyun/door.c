// Room: /d/paiyun/door.c

inherit ROOM;

void create()
{
	set("short", "կ��");
	set("long", @LONG
�����������������ڰ���·�ġ�����կ�����ߴ��կ�����
����裬����һ��������顱����կ���������֣�կ����¥�ϲ�
�ٰ��ź�ͷ�����ó�ǹ���ڱ�����߮��
LONG
	);
	set("outdoors", "paiyun");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"up4",
  "north" : __DIR__"lu1",
]));

	set("objects",([
	__DIR__"npc/door_guard" : 1,
]));

	setup();
}

int valid_leave(object who,string dir)
{
	if(dir == "north"
	&& present("shan fei",this_object())
        && userp(who)
	&& !wizardp(who))
		return notify_fail("ɽ�˳���һ����˵����û����Զ�㣡˵�Ű�����˳�����\n");
	return ::valid_leave(who,dir);
}
