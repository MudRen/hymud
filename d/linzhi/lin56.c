// Room: /d/linzhi/lin56.c

inherit ROOM;

void create()
{
	set("short", "��ԭб·");
	set("long", @LONG
�����Ǹ�ԭб·�������ڸߵͲ�ƽ��б�µ��ϣ����ɵô���
��־��񡣺�Ȼһֻ�������������ӵĶ���������ǰ�ܹ���գ��
��û��ݴԲ����ˣ������ʮ����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin55",
  "southeast" : __DIR__"lin57",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4100);
	setup();
	replace_program(ROOM);
}
