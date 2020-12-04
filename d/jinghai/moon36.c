// Room: /d/jinghai/moon36.c

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
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"moon31",
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

	if( !objectp(present("tian key", me)) ) 
		return notify_fail("��բ�����أ�����Կ�׿��´򲻿���\n");

	if(!room = find_object(__DIR__"moon35"))
		room = load_object(__DIR__"moon35");
	if(!room)
		return notify_fail("��բ�޷��򿪡�\n");

	if(!room->query("exits/out"))
	{
		room->set("exits/out",__FILE__);
		tell_room(room,"ֻ������һ������բ��������\n");
	}
	set("exits/enter", __DIR__"moon35");

	tell_room(__FILE__,"ֻ������һ������բ��������\n");
	call_out("close",5);
	return 1;
}

void close()
{
	object room = find_object(__DIR__"moon35");

	if(query("exits/enter"))
	{
		tell_room(__FILE__,"ֻ��������������������բ�Զ��ر��ˡ�\n");
		delete("exits/enter");
	}

	if(!room)
		room = load_object(__DIR__"moon35");

	if(room && room->query("exits/out"))
	{
		room->delete("exits/out");
		tell_room(room,"ֻ��������������������բ�����عر��ˡ�\n");
	}

}
