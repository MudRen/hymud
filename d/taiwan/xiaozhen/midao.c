// Room: /d/taiwan/midao.c

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
һ��ʯͷ�̳ɵ��ܵ�,ֻ����һ����ǿ����,���ֱߵ�ʯ���ϵ����
һյ������,������ŵ�һ��ҹ���鷢�����̵Ĺ���.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"dating",
  "down" : __DIR__"midao1",
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "ҹ����" : "һ�Ż�Բ������,�ںڰ����ܹ�����.
",
  "������" : "��ʯͷ��̳ɵƵ���״,�ڵ�о�ĵط�,��һ�ŷ����Ĺ��ҹ����.
",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
