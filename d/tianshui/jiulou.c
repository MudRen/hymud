// Room: /xiaozhen/jiulou.c

inherit ROOM;

void create()
{
	set("short", "���ɸ�");
	set("long", @LONG
����¥������Զ��������¥�ڸ���������ʳ����ߺ�������
���õ�С�����������˾��Ͳˣ��к����ˣ�¥����������
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"nroad1",
  "up" : __DIR__"jiulou2",
]));

	
	set("valid_startroom",1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/paotang" : 1,
]));

	setup();
	replace_program(ROOM);
}
