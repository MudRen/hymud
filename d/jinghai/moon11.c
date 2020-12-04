// Room: /d/jinghai/moon11.c

inherit ROOM;

void create()
{
	set("short", "��ջ��");
	set("long", @LONG
����һ������ʯƴ�̳ɵĵ�·����·���������������Բľ
Χǽ����·���ϱ����������ֱ�����ӿ�ȥ��ʱ��ʱ��һ�ӶӺ�
��ˮ�������������߲�Զ���Կ���һ���յء��ϱ�����ֱ�
��ˮկ�ı�����͵�����Ϣ�ҵ����ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"moon14",
  "east" : __DIR__"moon7",
  "south" : __DIR__"moon15",
]));
        set("outdoors","jinghai");
        set("objects",([
        __DIR__"npc/kanshou1" : 1,
]));

	

	setup();
}

int valid_leave(object who,string dir)
{
	object npc;

	npc=present("kan shou",this_object());

	if(dir=="east" || dir == "e")
	{
		who->delete_temp("can_enter_wuqi");
		return ::valid_leave(who,dir);
	}

	if( (dir == "north")
	&& !wizardp(who)
	&& (who->query("class") != "jinghai")
	)
		return notify_fail("�Ǳ��ɵ��Ӳ��ý�����Ϣ�ң�\n");
	if(npc
	&& (dir == "south" || dir == "s")
	&& !who->query_temp("can_enter_wuqi") )
		return notify_fail("����˵����û�����������������⡣\n");

	return ::valid_leave(who,dir);
}
