// Room: /d/fengtian/kd2.c

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

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"kd3",
  "south" : __DIR__"midian",
  "east" : __DIR__"kd1",
]));
        set("outdoors", "fengtian");

	set("objects",([
	"/clone/npc/man" : 2,
]));

	setup();
	replace_program(ROOM);
}
