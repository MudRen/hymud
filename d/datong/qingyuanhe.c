// Room: /open/dt/qingyuanhe.c

inherit ROOM;

void create()
{
	set("short", "��Ԫ��");
	set("long", @LONG
��Ҿ�¥�ڴ�ͬ��������һָ�ģ�����¥��װ諰���ø���
�ûʣ�����ĺ��ռ���ζ��֮�����ڷ�Բ��������Ҳ�Ҳ����ڶ�
�ҿ���֮�������ˣ����⻹������������Ʋˡ���������Ʋ���
�С�ͷ�ԡ����ഫ��ҽ�ɸ�ɽ�������䲻���ζ���Ѷ���������
����������Ƣ����һ�����е��̲�ʳƷ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"youfujie1",
]));

	setup();
	replace_program(ROOM);
}
