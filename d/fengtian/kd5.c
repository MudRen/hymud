// Room: /d/fengtian/kd5.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����·��ʢ���ϳǵ���Ҫ�ֵ�������·�ᴮ������ʢ���ǵ�
һ���Ͻ֣��ֵ�����ʯ�������ߵ���ͷ���˶�����ֻ���������
�������в���С�̵꣬��Ӫ������ʳס���Լ����ӵĻ��
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"kd6",
  "south" : __DIR__"rou",
  "east" : __DIR__"lukou",
  "north" : __DIR__"yao",
]));
        set("outdoors", "fengtian");

	set("objects",([
	"/clone/npc/man" : 1,
]));

	setup();
	replace_program(ROOM);
}
