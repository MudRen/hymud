// Room: /d/zuojiacun/lu3.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
��Ţ��С·�ϵ�����ˮ��������·��Ū������ʪ�����ġ�һ
Щ��ŵĴ帾�������������ߣ�ȴ����������ϵ���ˮ��·��
�ϲ���һ��С�ꡣ
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yuju",
  "west" : __DIR__"lu2",
  "east" : __DIR__"lu4",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
