// Room: /d/5lt/exit.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���������ݽ��⣬��ȻԶ���سǣ�ȴû��ʲ��ɽ���ݿ��ڸ�����û��
������һ��С��ׯ�������ǹ����ճ������������Ϣ���������ٲȻ
������Դ��Ȼ�Եõ����ӡ�
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"qsroad",
		"east" : "/d/taohuacun/taohua1",
					]));
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
//	set("no_clean_up", 0);
        set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);
	set("coor/x", -110);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}