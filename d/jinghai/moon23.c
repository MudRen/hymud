// Room: /d/jinghai/moon23.c

inherit ROOM;

void create()
{
	set("short", "ɽ��Сͤ");
	set("long", @LONG
������ɽ�ԵĶ��ˣ�һ���߽�ͩľͤ���������������ҡ
��������һɫ�����������˸о��Ŀ����������µ�Сɽ·������
�ϱߵ�ɽ�¡�·�ߵ�Ұ�ݴ����������˼����������ӡ���紵��
�Ӳ�ɪɪ���졣��ʱ���к��������ŷ�����ͷ����
LONG
	);
	set("outdoors", "jinghai");
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"moonlu1",
  "south" : __DIR__"moon2",
]));

	setup();
	replace_program(ROOM);
}
