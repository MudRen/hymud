
// Room: /d/snow/innerhall.c

inherit ROOM;

void create()
{
	set("coor",({-25,-50,0}));
	set("short", "�����Ժ");
	set("long",
"�����Ǵ�����ݵ���Ժ��ƽ����ݵ���û�й����������ǲ��ҵ��������ġ��Ա�����¥��ͨ\n"
"����ݶ�¥�����������ҵ����ã������ͼҾ���Է��ֱ�λ�����һ���ߵ������ԣ�������\n"
"���񷿡����۵��Է��������ϵ��ߵ����ԣ����������쾮��\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"inneryard",
  "up" : __DIR__"floor2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
