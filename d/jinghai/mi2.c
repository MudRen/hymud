// Room: /d/jinghai/mi2.c

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
  "west" : __DIR__"mi3",
  "east" : __DIR__"mi1",
]));

	setup();
	replace_program(ROOM);
}
