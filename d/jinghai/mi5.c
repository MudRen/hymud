// Room: /d/jinghai/mi5.c

inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ�����ĵ���ͨ����ͨ�������ǽ���ϵ�����ڴֵ�
��ѣ����ϵ�ϸɰ��Щ��ʪ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"mi4",
  "out" : __DIR__"wm15",
]));

	setup();
	replace_program(ROOM);
}
