// Room: /d/fengtian/quest1.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
����һ�������СԺ�ӣ����ϳ�������ݣ��ݶ��������м�
��ʯ��ʯ��ɢ�䣬����̮����Ժǽ����һ��ȱ�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"out" : __DIR__"fangjia",
	"west" : __DIR__"quest2",
]));

	setup();
	replace_program(ROOM);
}
