// Room: /d/jinghai/wm2.c

inherit ROOM;

void create()
{
	set("short", "������ǰ����");
	set("long", @LONG
����������ǰ��һ�������ʮ���Ļ��Ǻӣ������ɶ����
���������һ˫������ľ���ţ��ɴ�������������������ȥ����
һ����¥���������Ʈ�Ρ������Ĺ��г����Ϸ����š�����
��������������֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"wm12",
]));
        set("outdoors","jinghai");

	setup();
}

void init()
{
	add_action("do_han", "yell");
}

int do_han(string arg)
{
	object me, key, nroom;
	string passwd;

	me = this_player();

	if( !arg
	|| !(passwd = me->query_temp("jinghai_wm_passwd"))
	|| (arg != passwd))
		return notify_fail("�㳶�Ų��Ӻ��˼�ɤ�ӣ���Χ����û���κη�ӳ��\n");

	if( !(key = present("bai ling", me))
	|| (key->query("master") != me->query("id")))
		return notify_fail("����̽���˸��Դ����˿��������˻�ȥ��\n");

	if( !(nroom = find_object(__DIR__"wm3")) )
		nroom= load_object(__DIR__"wm3");

	set("exits/westup", __DIR__"wm3");

	message_vision("����̽���˸��Դ����˿�$N��$N�Ͻ������е������ó������˻Ρ�\n", me);
	message_vision("ֻ���������˺���Щʲô�������������¡�\n", me );

	me->delete_temp("jinghai_have_ling/bai");
	destruct(key);

	me->delete_temp("jinghai_wm_passwd");
/*
	me->set_temp("used_bailing", 1);
*/
	call_out("open",10,me);
	return 1;
}

void open()
{
	message("vision", "ֻ���������˺���:����...���š�\n", this_object() );
	delete("exits/westup");
}
