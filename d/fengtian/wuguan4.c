// Room: /d/fengtian/wuguan4.c

inherit ROOM;

void create()
{
	set("short", "�ҿ�Ժ");
	set("long", @LONG
������������ݵ��ҿ�Ժ��Ժ����һ�ھ����Դ�ˮ(fill)��
���������ٵ���������
LONG
	);

	set("resource/water", 1);
	set("cannot_build_home", 1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wuguan2",
]));

	set("outdoors","fengtian");
	setup();
	replace_program(ROOM);
}
