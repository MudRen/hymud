// Room: /u/xiaozhen/linlu1.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������һƬ�ž���С���֣�һ��΢�紵������Ҷɳɳ�����졣
������һ������С·��·�ߵĵ��ϲ�������Ҷ������������С·
�Ǿ��������ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"linlu2",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	if(!arg) return 0;
	if( arg!="��ǽ" && arg!="door") return 0;
	message_vision("$N�������Ϻ�ǽ��һ��ת���˹�ȥ��\n", this_player());
	this_player()->move(__DIR__"caizhu3");
	message("vision", this_player()->name() + "�Ӻ�ǽ����һͷ���˹�����\n",environment(this_player()), this_player());
	return 1;
}