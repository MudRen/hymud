// bingqipu.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ǳ������ı����̣������������²���̫ƽ�����Ա�����
������Ƚϻ��ȣ���������ȴ�Ե÷ǳ������塣ֻ��ż�����˴Ҵ�ææ
���������������ִҴ�ææ�뿪����Ȼ�������ⲻ�ã��������ﶫ����
����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"shilu3",
]));

	set("objects", ([
		__DIR__"npc/weaponboss.c" : 1,
	]));

	setup();
	replace_program(ROOM);
}
