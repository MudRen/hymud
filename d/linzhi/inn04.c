// Room: /d/linzhi/inn04.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ��װ�ε�ʮ�ֺ����Ĳ�����ͨ����Ǯ�˶���������
��һЩ���ѱ���һ��Ư���Ĳ���Ů�����ڲ������ӣ��������
������������Ļ΢Ц������������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"inn01",
  "east" : __DIR__"inn03",
]));

	setup();
	replace_program(ROOM);
}
