// Room: /d/linzhi/lin66.c

inherit ROOM;

void create()
{
	set("short", "��ɽ��ĹȺ");
	set("long", @LONG
���������ɽ��ĹȺ�ˣ����ƺ�ΰ���������أ�����ĹȺ��
�༸��˾���������ؾ��������ټ������ߵ����ͻȻ�е�Ī��
�Ŀ־壬�ƺ���˯���µķ����ں����������꣬�㲻���ӿ���
�Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin66",
  "southeast" : __DIR__"lin64",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3400);
	setup();
	replace_program(ROOM);
}

