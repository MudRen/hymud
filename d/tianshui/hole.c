// Room: /d/china/junying/xiaozhen/enter_hole.c

inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
����һ����ɭɭ�Ĵ�ɽ�������涴�׶�������������ֱ��һ
���Ի���ʯ�����������ˮ�飬���Ϸǳ���Ţ��

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xianjing_entry",
  "south" : __DIR__"enter_hole",
]));

	set("objects",([
"/d/linzhi/npc/mob" : 3,
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}


