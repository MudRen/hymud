// Room: /d/jinghai/zhuque9.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ׯԺ�ڵĿ��������ڿ���������˸����ŷ��������
Բ��ʹ���ڸ�ֳַ����飬������һ���㰸������������������
���У�ÿ����������һ������Ů�����������׻�԰�ķ�����һ��
������������͸���������˽�����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "up" : __DIR__"zhuque11",
  "east" : __DIR__"zhuque8",
  "south" : __DIR__"zhuque10",
  "west" : __DIR__"zhuque7",
]));
        set("objects",([
       __DIR__"npc/master4" : 1,
       __DIR__"npc/yong4" : 1,
]));

	setup();
}

int valid_leave(object me,string arg)
{
	if( (arg == "up")
	&& !wizardp(me)
	&& (me->query("class") != "jinghai") )
		return notify_fail("�Ǳ��ɵ��Ӳ������ڣ�\n");

	else
		return ::valid_leave(me,arg);
}

