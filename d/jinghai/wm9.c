// Room: /d/jinghai/wm9.c

inherit ROOM;

void create()
{
	set("short", "����յ�");
	set("long", @LONG
���������������Ĺ㳡���㳡������һ���߸ߵ���¥������
���硣ÿ���峿�����������������ŵ������������������ĸ�
�����䡣�����˶�����������������������ྸ������ϲ���ۼ�
�����������ңң�ɼ�������ˮկ���š�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wm14",
  "east" : __DIR__"wm8",
  "south" : __DIR__"wm15",
  "west" : __DIR__"wm10",
]));
        set("outdoors","jinghai");

	setup();
}

int valid_leave(object me,string arg)
{
	if( (arg =="south" || arg =="s")
	&& !wizardp(me)
	&& (me->query("class") != "jinghai" ) )
		return notify_fail("ͻȻ�Աߴܳ�����������ס��˵�����鷿�ص����˲������ڣ���\n");

	else
		return ::valid_leave(me,arg);
}
