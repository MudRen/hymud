// Room: /d/fengtian/kd1.c

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
  "west" : __DIR__"kd2",
  "east" : __DIR__"lf1",
  "north" : __DIR__"ll4",
]));

	set("objects",([
		"/d/city/npc/xunbu" : 2,
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
