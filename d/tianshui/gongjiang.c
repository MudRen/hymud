// Room: /u/xiaozhen/gongjiang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������Ĺ������ү�ļң�����������˸��ֹ��ߣ���
����̯��һ��ͼ�����滭��һЩ��ֵķ��ţ����ү�������ӱߡ�
����С�������������֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wroad2",
]));
	set("objects",([
	__DIR__"npc/sunzi" : 1,
	__DIR__"npc/grand_li" : 1,
]));
	setup();
	replace_program(ROOM);
}
