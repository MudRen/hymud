// Room: /d/linzhi/inn03.c

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
�����ǿ͵��¥������һ�����վ�������������������
�Ĵ����к�������������һ��¥��ͨ����¥�ͷ���������һ����
�߼��Ĳ����������������õġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"inn01",
  "up" : __DIR__"inn05",
  "west" : __DIR__"inn04",
]));

	setup();
	replace_program(ROOM);
}
