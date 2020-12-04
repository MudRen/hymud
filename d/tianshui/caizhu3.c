// Room: /u/xiaozhen/caizhu3.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
���������լ�Ŀ�Ժ�ˣ�Ժ����ֲ�Ÿ��ֻ��ݣ����ϻ�����
����С������������������Ŀ���������һ��ľ�ܣ���ǽ���ֵ�
����˳��С��������һֱ����������ľ�ܣ����Ǹ���������ĺ�
ȥ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"caizhu2",
]));

	set("cannot_build_home",1);
	set("outdoors","tianshui");
	setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	if(!arg) return 0;
	if( arg!="��ǽ" && arg!="door") return 0;

	message_vision("$N�������Ϻ�ǽ��һ��ת���˹�ȥ��\n", this_player());
	this_player()->move(__DIR__"linlu1");
	message("vision", this_player()->name() + "�Ӻ�ǽ����һͷ���˹�����\n",environment(this_player()), this_player());
	return 1;
}