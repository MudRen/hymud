// yaopu.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������Ψһ��ҩ�̣��������￿����ɽ�����ԣ��������������
������ҩ�ġ������õ��ϰ���һλ��ͷ�ӣ����ų����ĺ��룬��Ȼ������
��д�������µĲ�ɣ����������һ˫�۾���������������
LONG
	);

	set("exits", ([
		"south" : __DIR__"shilu5",
	]));

        set("objects",([
		__DIR__"npc/yaoboss" : 1,
	]));
        
	setup();
	replace_program(ROOM);
}
