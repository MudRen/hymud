// Room: /d/lumaji/roupu.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ȼ���󣬵�ȴ���������򵽱�û�е�Ұζ����
Ϊ�������Ի�������������һЩû�õ�������ϰ����ڹ�̨��
����ź��̴����������������Ц��Ц��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu10",
]));

	set("objects",([
	__DIR__"npc/roupu_boss" : 1,
]));

	setup();
	replace_program(ROOM);
}
