// Room: /d/taiwan/dating.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʮ�ִ������,���ź�ľ����������һ���ſ�,���е�һ��̫ 
ʦ���ϻ����Ž���.������һƬ�ǽ�,����ˤ�Ƶ���,����,��Ȼ�������ɭ 
ɭ�׹Ǻ�����.���е�ǽ�Ϲ���һ���ͻ�ͼ. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"huilang",
]));
	set("item_desc", ([ /* sizeof() == 3 */
  "�ͻ�ͼ" : "����һ���ͻ���ɽͼ,һ��һ��,Ī���Ѿ�����.
",
  "ͼ" : "����һ���ͻ���ɽͼ,һ��һ��,Ī���Ѿ�����.
",
  "map" : "����һ���ͻ���ɽͼ,һ��һ��,Ī���Ѿ�����.
",
]));
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/zongwangshi.c" : 1,
  __DIR__"obj/chair.c" : 1,
  __DIR__"obj/powan.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
