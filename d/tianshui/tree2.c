// Room: /d/china/junying/xiaozhen/tree2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������ϣ���֦�ϻ�����һ���񳲡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tree1",
]));
	set("no_clean_up", 0);
	set("bird",1);
	setup();
}

void init()
{
	add_action("do_tao","tao");
}

int do_tao(string arg)
{
	object obj;
	if(!arg || arg == "") return 0;
	if(arg != "��" && arg != "nest") return 0;
	if(!query("bird")) 
	message_vision("$N�������������˼��£�����ʲôҲû�С�\n",this_player());
	else {
	obj = new(__DIR__"npc/bird");
	obj->move(this_object());
	message_vision("$N�������������˼��£�����������һֻС��\n",this_player());
	set("bird",0);
	this_player()->set_temp("tao_bird",1);
	}
	return 1;
}