// /guanwai/bingmian.c

inherit ROOM;

void create()
{
	set("short", "�ɻ�������");
	set("long", @LONG
�������ɻ����ϵĴ��ţ����˻���ƥ���������ɺ��������Σ�ա�
���������к��Ļ�ѩ������������һƬ��ֻ���м侭������֮
����¶��һ����ɫ�ı�·��
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"damenkan",
		"westdown"  : __DIR__"chuanchang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
