// Room: /d/jinghai/moon27.c

inherit ROOM;

void create()
{
	set("short", "���̨��¥");
	set("long", @LONG
������ȫˮկ����������㡣��կ���������ٴ˵أ�����ˮ
����µ�ѵ��������������ˮկ����ͷ���ϱ���ˮկ���ʡ�����
�︩��ȫկ�����Կ����ԶԱ����жӶ��У����뻮һ���ɼ���λ
կ��������ĩ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"moon17",
]));
        set("outdoors","jinghai");
        set("objects",([
        __DIR__"npc/yong1" : 1,
        __DIR__"npc/master9" : 1,
]));


	setup();
	replace_program(ROOM);
}
