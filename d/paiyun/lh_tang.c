// Room: /d/paiyun/lh_tang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������������կ�ľ���Ҫ�أ����þ�ͷ��һ�����磬������
һ��������������צ������ǰ����һ�ѽ��Σ�����һ�ŵ�����
��Ƥ����ǰһ���ź��׵�̺��������ʮ���Ž��Σ���ǽ�߷ŵ�
�Ǳ����ܣ�һʮ�˰����������ȫ��������������һ����ɱ�ķ�
Χ��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dayuan",
]));

	set("no_steal",1);
	set("objects",([
	__DIR__"npc/liguang" : 1,
	__DIR__"npc/fei_tou" : 2,
]));

	setup();
	replace_program(ROOM);
}
