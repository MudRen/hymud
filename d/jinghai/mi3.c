// Room: /d/jinghai/mi3.c

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
  "west" : __DIR__"mi4",
  "east" : __DIR__"mi2",
]));

	setup();
	replace_program(ROOM);
}
