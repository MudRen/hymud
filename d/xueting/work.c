// Room: /d/xueting/work.c
// by pian

inherit ROOM;

void create()
{
	set("short", "����վ");
	set("long", @LONG
ѩͤ�򶫱�����һ���ɿ󳡣������ǲɿ��ڴ�ڵĹ���վ��
һ��СС��ľ�����ڶ��ߣ��Ա���һ����ɽ��б�£�·����һ�ھ���
�յ���ͣ����������ʯ�ϵĳ���������һ��������ʯ���·��һ·
��ɽ�������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
//	"northeast" : __DIR__"diggroom",
//"south" : "/d/oldpine/npath1",
	"west" : __DIR__"path5",
	"east" : __DIR__"palace_path1",
]));
	set("no_clean_up", 0);
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

	setup();
	replace_program(ROOM);
}
