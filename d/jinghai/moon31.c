// Room: /d/jinghai/moon31.c

inherit ROOM;

void create()
{
	set("short", "�η���");
	set("long", @LONG
������һ����խ�Ĺ���������ͨ������η���ͨ�����ı���
������ʯ���ɡ�����ֻ��ǽ���ϵ�С�͵ƣ�����谵��ż��
���������еδ�δ����ˮ��������������һ��[����]�š���
�治ʱ���������ú��С�����ë���Ȼ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"moon36",
  "west" : __DIR__"moon30",
  "south" : __DIR__"moon33",
]));

	setup();
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object me, key, nroom;

	me= this_player();

	if( !arg && arg != "����" && arg != "silao")
		return notify_fail("Ҫ��ʲô��\n");

	if( !(key = present("si key", me)) ) 
		return notify_fail("����Կ�ף��������߿�����\n");

	if( !(nroom = find_object(__DIR__"moon32")) )
		nroom= load_object(__DIR__"moon32");

	set("exits/enter", __DIR__"moon32");
	message("vision", "ֻ������һ������������������\n",this_object() );

	me->set_temp("used_key3", 1);
	call_out("close",10,me);
	return 1;
}

int close()
{
	message("vision", "ֻ������������������������Ѹ�ٹ����ˡ�\n", this_object() );
        delete("exits/enter");
}
