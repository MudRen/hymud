
// Room: /d/snow/hroad1.c

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long",
"��һ·�����У����������ˬ���ٲݵ��㣬΢����棬���к��⡣·��ʱ�������糾������\n"
"��ɫ�Ҵҵز��������ż����װ�λ�������������߾����������������Լ������������\n"
"�����嶣����Զ����ɽ�͵��֣�ɽ������ɢ���ż���ũ��é�ᡣ\n"
);
        set("exits", ([ /* sizeof() == 2 */
]));
	set("no_clean_up",0);
        set("outdoors", "ny");
//	set("objects",(["/d/snow/npc/txtrainee": 3]));
        setup();
        replace_program(ROOM);
}
