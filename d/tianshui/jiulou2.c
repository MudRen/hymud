// Room: /d/china/junying/xiaozhen/jiulou2.c

inherit ROOM;

void create()
{
	set("short", "���ɸ��¥");
	set("long", @LONG
���������ɸ�Ķ�¥���������ɸ������������С���Ϻ���
���Ĵ�ٹ��˶��������÷�����������������������㳡��¥��
��һƬ���ｻ���ϰ����Ĵ��к��ſ��ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"jiulou",
]));
	set("objects",([
	__DIR__"npc/zuixiange_boss" : 1,
]));
        set("NORIDE","С��¥��̫խ������������������ϲ�ȥ��");
	setup();
	replace_program(ROOM);
}
