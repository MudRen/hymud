// Room: /d/zuojiacun/lu5.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
��Ţ��С·�ϵ�����ˮ��������·��Ū������ʪ�����ġ�һ
Щ��ŵĴ帾�������������ߣ�ȴ����������ϵ���ˮ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"haichan",
  "west" : __DIR__"lu4",
  "east" : __DIR__"lu18",
  "north" : __DIR__"lu6",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
