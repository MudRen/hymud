// Room: /d/fengtian/lian.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�ʵ��й�һ��Ҫ�����䳡�ˣ��Ͼ��ǻʵ�����ķ���������
��������ʮ���ֱ��������������λεģ��ʵ�ʱ�������ﳿ����
���һʵ��й�����ǹ����ͷ���������䡣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jjf4",
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
