// Room: /d/snow/guestroom.c

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
������һ�䲼�õ��൱���µ��᷿���Ӵ��ӿ��Կ������ߵ���
�����ϱߵ�ͥ԰�и�ʽ�������滨��ݣ��Լ������������ĵ�����
�����᷿�Ķ���ǽ�ϻ�����һ����Ůͼ(painting)��������һλ��
װ������������ͨ���쾮�ĳ��ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"inneryard",
]));
	set("no_clean_up", 0);
//        set("objects", ([
//                "/obj/muren": 3 ]) );

//	setup();
	replace_program(ROOM);
}
