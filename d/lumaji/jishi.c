// Room: /d/lumaji/jishi.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
����һ���òݴ�ɵ����ӣ����˶�����������Χ�źü�����
����ˣ��������ں��������ż�Ǯ�����Ｔ���������ҷ�ԭ��ʮ
����ֻ����һ�����У��������ﾭ��������֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yuan",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
