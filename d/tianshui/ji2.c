// Room: /d/china/junying/xiaozhen/ji2.c

inherit ROOM;

void create()
{
	set("short", "��ζ��");
	set("long", @LONG
������ǻ�ζ������С���ţ�����һ��С��������
���٣��������ҡ��Ա�һԲ�ʣ�����ԧ��档�ݽ�ľ��
�������ϴ����壬�����һ��ԧ��Ϸˮ��ǽ�ǹ���һ
��С׭������
		������״����У�ϧ�����񼸸�֪��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jiyuan2",
]));
	//set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_quit","quit");
}

int do_quit(string arg)
{
	object obj;
	if(this_player()->query_temp("jiyuan")) {
	if(obj = present("m_boss",find_object("/d/tianshui/jiyuan2")))
		obj->delete_temp("have_full");
	return 0;
	}
	return 0;
}

int valid_leave(object me,string dir)
{
	object obj;
	if(dir == "east" || dir == "e")
	{
	if(me->query_temp("jiyuan/sleep") != "����") return 1;
	call_out("zou_ren",1);
	me->delete_temp("jiyuan");
	if(obj = present("m_boss",find_object("/d/tianshui/jiyuan2")))
		obj->delete_temp("have_full");
	return 1;
	}

	return 1;
}

void zou_ren()
{
	object obj;

	if(obj = present("lian yu",this_object())) {
		tell_object(this_object(),obj->name()+"��Թ��̾��һ���������ˡ�\n");
		destruct(obj);
		}
}