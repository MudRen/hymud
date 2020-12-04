// Room: /d/jinghai/moon30.c

inherit ROOM;

void create()
{
	set("short", "�η���");
	set("long", @LONG
������һ����խ�Ĺ���������ͨ������η���ͨ�����ı���
������ʯ���ɡ�����ֻ��ǽ���ϵ�С�͵ƣ�����谵��ż��
���������еδ�δ����ˮ���������ܲ�ʱ���������ú��С���
��ë���Ȼ�����ϸ���һ������բ��
LONG
	);

       set("item_desc", ([ 
       "��բ" : "����һ����̴���բ����բ�Ա���һ��Կ�׿ס�\n",
]));
       set("exits", ([ 
       "east" : __DIR__"moon31",
       "north" : __DIR__"moon34",
]));

      setup();
}

void init()
{
      add_action("do_open", "open");
}

int do_open(string arg)
{
	object me,room;

	me= this_player();
	if( !arg && arg != "��բ" && arg != "zha")
		return notify_fail("Ҫ��ʲô��\n");

	if( !objectp(present("tie key", me)) ) 
		return notify_fail("��բ�����أ�����Կ�׿��´򲻿���\n");

	if(!room = find_object(__DIR__"moon29"))
		room = load_object(__DIR__"moon29");
	if(!room)
		return notify_fail("��բ�޷��򿪡�\n");

	if(!room->query("exits/down"))
	{
		room->set("exits/down",__FILE__);
		tell_room(room,"ֻ������һ������բ��������¶�������µĳ��ڡ�\n");
	}
	set("exits/up", __DIR__"moon29");

	tell_room(__FILE__,"ֻ������һ������բ��������¶�������ϵĳ��ڡ�\n");
	call_out("close",5);
	return 1;
}

void close()
{
	object room = find_object(__DIR__"moon29");

	if(query("exits/up"))
	{
		tell_room(__FILE__,"ֻ��������������������բ�Զ��ر��ˡ�\n");
		delete("exits/up");
	}

	if(!room)
		room = load_object(__DIR__"moon29");

	if(room && room->query("exits/down"))
	{
		room->delete("exits/down");
		tell_room(room,"ֻ��������������������բ�����عر��ˡ�\n");
	}

}
