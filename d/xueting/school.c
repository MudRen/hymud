// Room: /d/snow/school.c

inherit ROOM;

void create()
{
	set("short", "�޼���Ժ");
	set("long", @LONG
������һ�������Ժ����Ȼ���ӿ��������Ͼ��ˣ����Ǵ�ɨ
�ú����࣬ǽ���Ϲ���һ��ɽˮ�����⾳��Ϊ���ף���Ժ�Ĵ��ſ�
�ڱ��ߣ�������һ��ľ��ͨ�����ᡣ
LONG
	);
	
	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"wstreet1",
	]));
	set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/teacher" : 1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
