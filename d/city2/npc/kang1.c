// Room: /city2/kang1.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ��
��ס�˴������ࡣ�����д����������أ��䱸ɭ�ϡ����Ϲ�����
����������Ȼд�Ŵ��ġ������֡�
LONG
	);

	set("exits", ([
		"south" : __DIR__"wangfu3",
		"north" : __DIR__"kang2",
	]));


	setup();
}

