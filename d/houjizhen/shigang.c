//shigang.c
//by dicky

inherit ROOM;

void create()
{
set("short", "��ʯ��");
	set("long", @LONG
������һ����᫲�ƽ����ʯ���ϣ�ż������һ�����Ұ�޺�������ͷ��
��һЩ��֪����С����������ȥ�����ܴ����ܲ���Ұ���̲��������֣�����
���紵�������Ȼ��һ��ë����Ȼ�ĸо�,���ɵļӿ��˽Ų���
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 1 */
	    "southeast" : __DIR__"tomb",
	    "northup" : __DIR__"shanpo",
	    "west" : __DIR__"lzxiaolu",
]));

//	set("objects", ([
//		__DIR__"npc/tufei" : 3,
//		]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

