// Room: /d/lumaji/yuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
����һ������Ժ�ӣ��ϱ�����ȫ�Ǹ��ָ�������ƥ��һЩ
���������������ڶ��׵Ĳ����оۼ��ţ���ʱ��������ʲô��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"juan",
  "east" : __DIR__"jishi",
  "west" : __DIR__"lu6",
]));
	set("outdoors", "lumaji");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
