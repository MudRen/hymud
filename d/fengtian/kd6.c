// Room: /d/fengtian/kd6.c

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

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kd5",
  "northwest" : __DIR__"kd7",
]));

	set("objects",([
"/clone/npc/man" : 1,
]));

        set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
