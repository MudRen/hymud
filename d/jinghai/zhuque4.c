// Room: /d/jinghai/zhuque4.c

inherit ROOM;

void create()
{
	set("short", "������ȸ�ô���");
	set("long", @LONG
������һ���ܴ��ׯԺ�����ɺ�ΰ�ľ�����ȸ�ô���������
��ʮ��̨���ϣ��߸ߵ���¥�ϣ���ͭ��ɵ�˫�ഩ��ͼ��������
�����ɫ�����ϵ�ͭ��ĥ�������һ������֮����Ȼ�������㲻
���������½��ƺ��������ڰ��в鿴���һ��һ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhuque1",
  "south" : __DIR__"zhuque6",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
