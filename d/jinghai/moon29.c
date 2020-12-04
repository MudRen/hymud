// Room: /d/jinghai/moon29.c

inherit ROOM;

void create()
{
	set("short", "���ο��ط�");
	set("long", @LONG
�����ǿ�����ƽ�����ĵط�����С���ֻ谵��С���ڣ����
��һ��С���������վƺ���б�ķ��������ϡ����������������
����˯�����ţ�ǽ�Ϲ��Ÿ�[�̾�]���ӣ��������������˵Ĺ���
֮��Ķ�����һ��[��բ]��ס���µ����ε�ȥ·��û��Կ���ǲ�
���ܽ�ȥ�ġ�
LONG
	);
       set("item_desc", ([ 
	"��բ" : "����һ����̴���բ����բ�Ա���һ��Կ�׿ס�\n",
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"moon28",
]));

	setup();
}
void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
	object me,room;

	me= this_player();
	if( !arg && arg != "��բ" && arg != "zha")
		return notify_fail("Ҫ��ʲô��\n");

	if( !objectp(present("tie key", me)) ) 
		return notify_fail("��բ�����أ�����Կ�׿��´򲻿���\n");

	if(!room = find_object(__DIR__"moon30"))
		room = load_object(__DIR__"moon30");
	if(!room)
		return notify_fail("��բ�޷��򿪡�\n");

	if(!room->query("exits/up"))
	{
		room->set("exits/up",__FILE__);
		tell_room(room,"ֻ������һ����ͷ�ϵ���բ��������¶�������ϵĳ��ڡ�\n");
	}
	set("exits/down", __DIR__"moon30");

	tell_room(__FILE__,"ֻ������һ������բ��������¶�������µĳ��ڡ�\n");
	call_out("close",5);
	return 1;
}

void close()
{
	object room = find_object(__DIR__"moon30");

	if(query("exits/down"))
	{
		tell_room(__FILE__,"ֻ��������������������բ�Զ��ر��ˡ�\n");
		delete("exits/down");
	}

	if(!room)
		room = load_object(__DIR__"moon30");

	if(room && room->query("exits/up"))
	{
		room->delete("exits/up");
		tell_room(room,"ֻ������������������ͷ�ϵ���բ�����عر��ˡ�\n");
	}

}
