// Room: /d/fengtian/n_gate.c

inherit ROOM;

void create()
{
	set("short", "ʢ������");
	set("long", @LONG
��Ϊ��������ʢ���ĳ��Ÿߴ����ΰ������һֱ�ǿ�������
������������Ĺؿڣ������Ϸ����Źپ������Ǿ��죬����һ��
������������צ����ǽ��һ�����������������ʢ���ǣ�������
�����վ��ǳ���
LONG
	);

	set("exits", ([
	"south" : __DIR__"guanlu4",
	"north" : __DIR__"out_fengtian_n",
]));
        set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
