// Room: /d/lumaji/lu14.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
���ߵ����ֻ��һЩ�帾����������·��ϴ�·���������
����������Ц��Ц�ֵ���ͷæ�Լ������ˡ�����һЩС��������
·����ˣ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu12",
  "east" : __DIR__"lu15",
  "south" : __DIR__"caifeng",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
