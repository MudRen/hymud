// Room: /d/zuojiacun/lu4.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
��Ţ��С·�ϵ�����ˮ��������·��Ū������ʪ�����ġ�һ
Щ��ŵĴ帾�������������ߣ�ȴ����������ϵ���ˮ��·��
������һ���ӻ��ꡣ
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu3",
  "east" : __DIR__"lu5",
  "north" : __DIR__"zahuo",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
