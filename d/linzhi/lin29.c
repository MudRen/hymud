// Room: /d/linzhi/lin29.c

inherit ROOM;

void create()
{
	set("short", "��ԭ����");
	set("long", @LONG
�����Ǹ�ԭ���£�ɽ����������ǰ����һ����ɽ���������
���ң�ͺӥ����հ��衣������񣬷ܲ���ǰ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin10",
  "southwest" : __DIR__"lin30",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
