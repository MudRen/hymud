// Room: /open/dt/shutang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ʮ���������ڸ��Ž����������飬һ�����ʵĶ���������
���лص�����ͬ�����䣬����һ���˼ҵĺ��Ӻ����е���������
�ģ��������Щ������ǹٻ��ӵܡ�����������һλ��ѧ������
��һ���۾���ҡͷ���Ե�ֻ�����飬�ƺ�û�о�����ĵ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huayanlu3",
]));

	setup();
	replace_program(ROOM);
}
