// Room: /d/paiyun/lu2.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
���۵�С·������ǰ�����ߵĽ���Ҳ������������Ӫ�����
����ʿ��Խ��Խ�࣬һЩ�帾������������ԶԶ������Կ���һ
Щɽ�ߴ��Ľ�����
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"yingfang",
  "south" : __DIR__"lu1",
  "east" : __DIR__"chaifang",
  "north" : __DIR__"dayuan",
]));
	set("outdoors", "paiyun");

	set("objects",([
	__DIR__"npc/shanfei" : 2,
	__DIR__"npc/fei_tou" : 1,
]));

	setup();
	replace_program(ROOM);
}
