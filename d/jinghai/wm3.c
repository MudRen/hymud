// Room: /d/jinghai/wm3.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
�������ĳ��š����߳����ĳ�ǽ��ʯ�����ͣ�������һ����
�ʵĳ�¥���������Ȼ�ͭ��Ӳľ���ţ�����˫����ʯ������ͨ
�����⡣��¥��������ʯǽ��¥��վ�����м��������Դ�����
�߳���������һ�Ÿ�ʾ(gaoshi)��һ��Ⱥ�˼������ܣ���ͷ�Ӷ�
��֪��������ʲô��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southup" : __DIR__"wm5",
  "northup" : __DIR__"wm4",
  "eastdown" : __DIR__"wm2",
  "west" : __DIR__"wm8",
]));
        set("objects",([
        __DIR__"npc/yong5" : 2,
        __DIR__"npc/duizhang1.c" : 1 ,
]));

        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
