// Room: /open/dt/chouduanzhuang.c

inherit ROOM;

void create()
{
	set("short", "���ׯ");
	set("long", @LONG
���ڵ�ǽ���Ϲ�����������ɫ�Ĳ�ƥ�ͳ��£���������̨��
Ҳ���ɾ�Ĳ������ˡ���������Ů��һ�渧����һƥ������У�
һ��͵������ּۻ��ۡ������˿������������æƲ������Ů��
����ǰ��������к���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huaandao1",
]));

	setup();
	replace_program(ROOM);
}
