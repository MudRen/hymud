// Room: /d/fengtian/kd4.c

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
  "west" : __DIR__"lukou",
  "south" : __DIR__"kedian",
  "east" : __DIR__"kd3",
]));
        set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
