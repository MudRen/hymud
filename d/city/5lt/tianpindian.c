// Room: /d/5lt/tianpindian.c

inherit ROOM;

void create()
{
	set("short", "��Ʒ��");
	set("long", @LONG
����һ����ʳƷ��С���ӣ��������кö�ö�ԵĶ�������ֱ����
��������Ŀ�����ݡ������ϰ����Ǵ峤�Ŀ��ģ�̨�������ã����Ե���
�����Ǵ���ͷ�������ĺ�!
LONG );
	set("exits", ([
		"north" : __DIR__"eroad1",
	]));
        set("objects", ([
		__DIR__"npc/blueeye": 1,
	]));
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -140);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}