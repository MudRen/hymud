// Room: /d/paiyun/lin2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ���֣���Ҷ��ס�����⣬�������������ƺ���һ������
�Ķ���������ñ���һ����粻�ɵļӿ��˽Ų���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kongdi",
]));
	set("outdoors", "paiyun");

	set("objects",([
	__DIR__"npc/shanfei" : 2,
	__DIR__"npc/fei_tou" : 1,
]));

	setup();
	replace_program(ROOM);
}
