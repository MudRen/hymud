// Room: /d/linzhi/by03.c

inherit ROOM;

void create()
{
	set("short", "��б��");
	set("long", @LONG
�����ǰ�һ����б�֣��������ʷ���һ���ӻ��꣬������
����һ�����̡���Ȼһ����ӭ��������������һ��ʲô��Ҳû
���߿��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"by02",
  "northwest" : __DIR__"by04",
  "west" : __DIR__"shop",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
