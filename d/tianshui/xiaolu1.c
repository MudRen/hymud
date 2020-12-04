// Room: /d/tianshui/xiaolu1.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
��������ˮ����ͨ����ԭ��һ��С·��·����һ�ô�������
������ˮ��Ķ���ңң������һ����·�����졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ekou",
  "northeast" : __DIR__"xiaolu2",
]));
	set("item_desc",([
	"tree" : "һ�ò���Ĵ�����\n",
	"����" : "һ�ò���Ĵ�����\n",
]));

	set("objects",([
	"/clone/npc/man" : 4,
]));

	set("outdoors","tianshui");
	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object room;
	if(!arg || arg == "") return 0;
	if(arg != "tree" && arg != "����") return 0;

	message_vision("$N����������ȥ��\n",this_player());
	this_player()->move(__DIR__"tree1");
	room = find_object(__DIR__"tree1");
	tell_object(room,this_player()->name()+"����������������\n");
	return 1;
}
