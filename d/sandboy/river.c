// Room: /d/sandboy/river.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��������ˮ,�����뺣,���紵��,����΢΢�Ľ�ˮ����Ϣ,�������
�ݰѽ�����׺�÷�������,���ĶԶ˾��Ǳ��ұ���֮��---����.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"to_sandboy",
  "south" : __DIR__"shulin",
]));
	set("outdoors", "/d/jiangnan");

	setup();
	replace_program(ROOM);
}
