// Room: /d/jinghai/moon8.c

inherit ROOM;

void create()
{
	set("short", "��ջ��");
	set("long", @LONG
����һ������ʯƴ�̳ɵĵ�·����·���������������Բľ
Χǽ����·���ϱ����������ֱ�����ӿ�ȥ��ʱ��ʱ��һ�ӶӺ�
��ˮ����������������ˮկ���ʡ����߲�Զ���Կ���һ����
�ء���������ֱ���ˮկ���鷿�Ϳͷ���
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"moon7",
  "east" : __DIR__"moon19",
  "west" : __DIR__"moon18",
  "south" : __DIR__"moon9",
]));
        set("outdoors","jinghai");

	setup();
}

int valid_leave(object me,string arg)
{
	if( (arg =="east" || arg =="e")
	&& !wizardp(me)
	&& (me->query("class") != "jinghai" ) )
		return notify_fail("ͻȻ�Աߴܳ�����������ס��˵�����鷿�ص����˲������ڣ���\n");

	else
		return ::valid_leave(me,arg);
}
