// Room: /d/lumaji/s_kou.c

inherit ROOM;

void create()
{
	set("short", "¹���Ͽ�");
	set("long", @LONG
��������ϴ���ˣ�·������һ�����ӣ�����д�š�¹����
�����֡���Բ��ʮ����Ψһ�����о��ڴ�����Ծ���������
������Ⱥ�����������ִ�����ȥ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/annan/shulin9",
  "north" : __DIR__"lu10",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
