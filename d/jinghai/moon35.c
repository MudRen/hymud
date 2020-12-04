// Room: /d/jinghai/moon35.c

inherit ROOM;

void create()
{
	set("short", "���ֺ��η�");
	set("long", @LONG
������һ��������ʪ��Сʯ�ң�ֻ��һյС�͵Ƹ�����ʯ��
�Ϸ�������տ���Ҳ��ֻ�м����Ʋ�ϯ���ڵ��ϡ����ﳱʪ����
��������̦�����Ӷ���������һ���ִܴ��������������������
���ˡ����ƣ�����صò����ط����Ƿ��ӡ��ſ��Ϲ�һ��Сľ��
����д�� [��]��
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/master7" : 1,
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

	if(!room = find_object(__DIR__"moon36"))
		room = load_object(__DIR__"moon36");
	if(!room)
		return notify_fail("��բ�޷��򿪡�\n");

	if(!room->query("exits/enter"))
	{
		room->set("exits/enter",__FILE__);
		tell_room(room,"ֻ������һ������բ��������\n");
	}
	set("exits/out", __DIR__"moon36");

	tell_room(__FILE__,"ֻ������һ������բ��������\n");
	call_out("close",5);
	return 1;
}

void close()
{
	object room = find_object(__DIR__"moon36");

	if(query("exits/out"))
	{
		tell_room(__FILE__,"ֻ��������������������բ�Զ��ر��ˡ�\n");
		delete("exits/out");
	}

	if(!room)
		room = load_object(__DIR__"moon35");

	if(room && room->query("exits/enter"))
	{
		room->delete("exits/enter");
		tell_room(room,"ֻ��������������������բ�����عر��ˡ�\n");
	}

}
