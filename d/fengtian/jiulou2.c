// Room: /d/fengtian/jiulou2.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����Ǿ�¥�ĺ���������������������һ����̨������
�����޴��ˮ�ױ�����һ���ľ��������ļ����϶������ù���
������ӡ��ſڹ���һ��ľ����(pai)��
LONG
        );

	
	set("exits",([
		"east" : __DIR__"jiulou",
]));
        set("item_desc",([
                "pai" : "����ϴ(xi)���ӡ�ϴ���С����\n",
]));

	set("objects",([
	__DIR__"npc/cooker" : 1,
]));
	setup();
	replace_program(ROOM);
}
