// Room: /d/lumaji/ws_home.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǵ��������ļң�������������һλ����͵��ϸ�����
�������棬���������ò���ĸ�ס����ﶫ�����٣�һ����֪����
�Һ����������δ�У�����ֻ�ô��Ϊ����ż���д���������
д�����֣�������˵��Ҳ��һ�ʿɹ۵����롣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu15",
]));

	setup();
	replace_program(ROOM);
}
