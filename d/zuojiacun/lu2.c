// Room: /d/zuojiacun/lu2.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
��Ţ��С·�ϵ�����ˮ��������·��Ū������ʪ�����ġ�һ
Щ��ŵĴ帾�������������ߣ�ȴ����������ϵ���ˮ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu1",
  "east" : __DIR__"lu3",
  "north" : __DIR__"ju1",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
