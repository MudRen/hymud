// midao2.c
// by dicky

inherit ROOM;

void create()
{
  set("short","����");
  set("long", @LONG
�������ǰһ�������Ǳ��ж��죬������һ�䲼�÷ǳ����������ҡ�
��ǽ��һ�Ŵ�����������һ��������У�����ͻȻ���������������ϴ�
����һԾ�����Աߵ�Ů���ܵ����ţ���������ļ�����������ڴ���
������ֱ���������һ˫������������㡣
LONG  );

	set("exits",([
	"west"  :__DIR__"midao1",
	]));

	set("sleep_room", 1);

        set("objects",([
		__DIR__"npc/xiaojie" : 1,
		__DIR__"npc/heshang" : 1,
	]));

	setup();
	replace_program(ROOM);
}
