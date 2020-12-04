// Room: /d/fengtian/quest4.c

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
����һ���������С�����������ϲ���һֻ��ѡ�ӭ�����
ǽ��Ƕ��һ��ʯ�塣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"quest3",
]));

	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player(),ob;

	if(arg != "ʯ��")
		return notify_fail("��Ҫ��ʲô��\n");

	ob = find_object(__DIR__"quest5");
	if(!ob)
		ob = load_object(__DIR__"quest5");

	if(!ob || (me->query("force") < 200))
		return notify_fail("����������һ�£�����ʯ����˿û����\n");

	message_vision("$N�ƿ�ʯ�壬����¶����һ�����ڡ�\n",me);

	tell_room(ob,"�����ƿ�ʯ�壬¶����һ�����ڡ�\n");

	set("exits/north",__DIR__"quest5");
	ob->set("exits/south",__DIR__"quest4");

	call_out("do_close",8);
	return 1;
}

private void do_close()
{
	object ob;

	tell_room(__FILE__,"ʯ���������ƻ���ԭλ��\n");
	delete("exits/north");

	ob = find_object(__DIR__"quest5");
	if(!ob)
		ob = load_object(__DIR__"quest5");

	if(ob)
	{
		tell_room(ob,"ʯ���������ƻ���ԭλ��\n");
		ob->delete("exits/south");
	}
}
