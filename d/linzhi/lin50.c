// Room: /d/linzhi/lin50.c

inherit ROOM;

void create()
{
	set("short", "��֥��ȪȺ��");
	set("long", @LONG
��������֥����ȪȺ�������ڵ�ò�仯�������Ĵ�������Ȫ��
��ĸ���ʮ�ף�С��Ҳ�ж����ף������ϼѵ���ԡ��ˮ��֮����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wenquan01",
  "south" : __DIR__"lin49",
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
