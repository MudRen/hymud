// Room: /u/xiaozhen/linlu3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ����С�������ϣ����¿���һƬС���֣�������
�����Ľ�ӡ������ӡ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"linlu2",
  "northup" : __DIR__"linlu4",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tufei" : 2,
]));

	setup();
	replace_program(ROOM);
}
