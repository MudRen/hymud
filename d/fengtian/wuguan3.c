// Room: /d/fengtian/wuguan3.c

inherit ROOM;

void create()
{
	set("short", "���Ժ");
	set("long", @LONG
������������ݵ����Ժ������ݵĽ�ͷƽʱ��Ϣ�ĵط���
���������ٵ���������
LONG
	);

	set("cannot_build_home", 1);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wuguan2",
]));

	set("objects",([
	__DIR__"npc/jiaotou" : 3,
]));

	set("outdoors","fengtian");
	setup();
	replace_program(ROOM);
}
