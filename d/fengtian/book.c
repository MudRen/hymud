// Room: /d/fengtian/book.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����ϰ���һ�����ֵļһΪ�˾����ܸɣ���С��꾭Ӫ
���������ϣ�������һﻹϲ�����Ļ��ѣ����Բ�������������
�����С��꣬�����������ϰ�����е�С�鷳��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kd3",
]));

	set("objects",([
	__DIR__"npc/book_boss" : 1,
]));

	setup();
	replace_program(ROOM);
}
