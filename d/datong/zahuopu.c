// Room: /open/dt/zahuopu.c

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��ר��һЩ������Ʒ��С���̣���Ϊ�������������
ջ�����������ë�����ӡ�����֮����ճ���Ʒ�ǳ���������
����Ҳ����ҩ����ҩһ��Ľ����˳��õ���Ʒ�������������
С��������ȴ��ʵ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"hongchanglu3",
]));

	set("objects",([
	__DIR__"npc/zahuoboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
