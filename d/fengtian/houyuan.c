// Room: /d/fengtian/houyuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
����һ�������СԺ�ӣ����ϳ�������ݣ��ݶ��������м�
��ʯ��ʯ��ɢ�䣬Ժǽ��Щ�ط�Ҳ�Ѿ�̮����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"fangjia",
]));

	setup();
	replace_program(ROOM);
}
