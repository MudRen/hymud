// Room: /d/jinghai/moon32.c

inherit ROOM;

void create()
{
	set("short", "�����η�");
	set("long", @LONG
������һ��������ʪ��Сʯ�ң�ֻ��һյС�͵Ƹ�����ʯ��
�Ϸ�������տ���Ҳ��ֻ�м����Ʋ�ϯ���ڵ��ϡ����ﳱʪ����
��������̦�����Ӷ���������һ���ִܴ��������������������
���ˡ����ƣ�����صò����ط����Ƿ��ӡ��ſ��Ϲ�һ��Сľ��
����д�� [��]��
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qiufan2" : 1,
  __DIR__"npc/qiufan3" : 1,
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

	if( !(nroom = find_object(__DIR__"moon31")) )
		nroom= load_object(__DIR__"moon31");

	set("exits/out", __DIR__"moon31");
	message("vision", "ֻ������һ������������������\n", this_object() );

	me->set_temp("used_key3", 1);
	call_out("close",10,me);
	return 1;
}

int close()
{
	message("vision", "ֻ������������������������Ѹ�ٹ����ˡ�\n", this_object() );
	delete("exits/out");
}
