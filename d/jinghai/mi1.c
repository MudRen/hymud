// Room: /d/jinghai/mi1.c

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
  "west" : __DIR__"mi2",
  "out" : __DIR__"jhd7",
]));

	setup();
	replace_program(ROOM);
}
