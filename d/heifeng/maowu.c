// Room: /d/heifeng/maowu.c

inherit ROOM;

void create()
{
	set("short", "é����");
	set("long", @LONG
����һ�����é���ݣ�������ĳ���ǳ���ª���м�һ��
���ӣ���������(table)����һ����Ⱦ�����������������������
��������ס�����ӣ����Ĵ�ȴ����ɨ�ĸɸɾ�����
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shanya",
]));
	set("objects", ([
		__DIR__"npc/wolfdog" : 3,
	]));

	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if(!arg || (arg != "table" && arg != "����"))
		return 0;

	message_vision("$N�������Ƶ���һ��",me);

	if(undefinedp(query("exits/down")))
	{
		set("exits/down",__DIR__"midao1");
		tell_room(__FILE__,"¶����һ�����µĳ��ڡ�\n");
	}
	else
		tell_room(__FILE__,"��\n");

	call_out("do_close",8);
	return 1;
}

void do_close()
{
	if(!undefinedp(query("exits/down")))
	{
		tell_room(__FILE__,"���˴����潫���µĳ��ڹ��ϡ�\n");
		delete("exits/down");
	}
}
