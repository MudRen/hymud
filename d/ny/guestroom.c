
// Room: /d/snow/guestroom.c

inherit ROOM;

void create()
{
	set("coor",({-20,-55,0}));
	set("short", "�ͷ�");
	set("long",
"������һ�䲼�õ��൱���µ��᷿���Ӵ��ӿ��Կ������ߵ��쾮���ϱߵ�ͥ԰�и�ʽ������\n"
"�滨��ݣ��Լ������������ĵ����������᷿�Ķ���ǽ�ϻ�����һ����Ůͼ(painting)����\n"
"����һλ��װ����,������ͨ���쾮�ĳ��ڡ�\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"inneryard",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "painting" : "���Ƿ�����ϸ�����Ůͼ��ƽ���˼Ҳ������д���
�����
",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
