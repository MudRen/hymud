//Room: /u/lots/d/livingroom.c
// LOTS 1998/10/19

inherit ROOM;

void create()
{
	set("short", "�����˵������");
	set("long", @LONG
����ǰ����˵���Ӵ����㿴����Χһ����Ⱦ��װ�ι��ӣ����ֵ��š���Ȼ���˵�
�Ǹ����ڲ�ͬ���ˡ��ڶ����µ�����������స������һ����Ůվ�������ԡ�
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"south" : __DIR__"houhuayuan",
	]));

	set("objects", ([
		"/d/kaifeng/npc/wife" : 1,
	]));

	setup();
	replace_program(ROOM);
}
