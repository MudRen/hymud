// Room: /d/china/junying/xiaozhen/enter_hole.c

inherit ROOM;

void create()
{
	set("short", "ɽ�����");
	set("long", @LONG
������ɽ������ڣ�����Ұ�ݴ�����������һЩ��֪ʲô��
�����µĽ�ӡ��ǰ����һ���ں�����ɽ������֪�������ʲôΣ
�ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hole",
  "south" : __DIR__"xiaolu3",
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
