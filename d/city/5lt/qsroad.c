// Room: /d/5lt/qsroad.c

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ�����,���������ǳ���æ,��ʱ����������ҴҶ�
����������һƬƽ���Ĳݵأ�һЩ�в�����Ŀ�Ĵ���С���ڲݴ��г�û
ʮ�����ڵ��������ϱ��ǿ�˵أ��ո����˳�С�꣬���۵����������
������泩������ͨ���ڡ�
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"caodi",
            "south" : __DIR__"caidi",
            "west"  : __DIR__"eroad2",
            "east"  : __DIR__"exit",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -120);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}