// Room: /d/linzhi/lin56.c

inherit ROOM;

void create()
{
	set("short", "��ԭб·");
	set("long", @LONG
�����Ǹ�ԭб·�������ڸߵͲ�ƽ��б�µ��ϣ����ɵô���
��־��񡣺�Ȼһֻ�������������ӵĶ���������ǰ�ܹ���գ��
��û��ݴԲ����ˡ��������һƬ���֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin56",
  "south" : __DIR__"lin58",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
