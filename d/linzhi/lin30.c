// Room: /d/linzhi/lin30.c

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
  "northeast" : __DIR__"lin29",
  "southwest" : __DIR__"lin31",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3000);
	setup();
	replace_program(ROOM);
}
