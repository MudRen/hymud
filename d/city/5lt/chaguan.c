// Room: /d/5lt/chaguan.c

inherit ROOM;

void create()
{
	set("short", "��Ȼ���");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ����¥����
�������Ų輸�������辰��ľ����������ģ���Ŀ����ڻ����̸Ц����
��ͷ�Ӷ�����Ʒ����̸��������������ƹʺ�ҥ�ԣ������Ǹ������ڡ�
��ǽ���ż����ֻ��������޷����档�м�������ź�÷��������������
�״ɵʡ��˴��о����ţ���������֮�Ѵ���
LONG);
	set("resource/water", 1);
	set("exits", ([
		"west"  : __DIR__"sroad1",
	]));
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -140);
	set("coor/y", -15);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}