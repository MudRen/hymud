// jiuguan.c
// by dicky

inherit ROOM;
void create()
{
	set("short", "С�ƹ�");
	set("long", @LONG
    ��һ�߽������Ϳ�����˫�۾������Լ������ϣ�����һ����
�����ƾɵ�ľ��һ���ſ������ǵ����ż�λ���ˣ����ͷ���ƣ���
ͷ�Ӷ���������̬���죬һ����֪������ʲô���ˣ����û��ʲô��
�飬������Ҫȥ�����ǡ�
LONG
	);

	set("resource/water", 1);
	set("exits", ([
		"south" : __DIR__"shilu4",
	]));
	set("objects", ([
		__DIR__"npc/jiuboss" : 1,
	]));

	setup();
	replace_program(ROOM);
}
