// Room: /d/zuojiacun/lu13.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ���ӿ�����С·����һ����һ��ǳ���������棬·��
������Ů���ڼ��ſ�ϴ�£���������·�����ӣ�̧��ͷ��Ц����
����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lu14",
  "west" : __DIR__"business",
  "east" : __DIR__"ju2",	
  "north" : __DIR__"lu12",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
