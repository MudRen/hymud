// Room: /d/5lt/xiaolu.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ��ȥ����ԡ����С·��·���Զ������˴��������������ȴ�
ֲ�һ�����ǰ���΢����ˮ��Ϣ�ķ�Ʈ�˹������㲻�����˸����硣
LONG);
	set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);
	set("exits", ([
		"north"     : __DIR__"haitan",
		"southeast" : __DIR__"wroad4",
	]));

	set("no_clean_up", 0);
	set("coor/x", -195);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
