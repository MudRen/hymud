// Room: /d/fengtian/s_gate.c

inherit ROOM;

void create()
{
	set("short", "ʢ������");
	set("long", @LONG
ʢ�����Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭ
ͷ���С���������Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ���
�ء���������������׽��֮��Ĺٸ����档
LONG
	);


	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guanlu3",
  "south" : __DIR__"out_fengtian_s",
]));
	set("objects",([
		__DIR__"npc/city_guard" : 2,
]));

	set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
