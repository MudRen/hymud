// Room: /d/linzhi/lin45.c

inherit ROOM;

void create()
{
	set("short", "��ԭ������");
	set("long", @LONG
������һƬ�����֣����ܶ��Ǹߴ����Ҷ�ɡ���Χʮ�ֵİ�
�����ƺ���������������ص����������治ʱ���������������
������һƬ���֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin42",
  "south" : __DIR__"lin46",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4000);
	setup();
	replace_program(ROOM);
}
