// Room: /d/fengtian/yao.c

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
ҩ���̨����Ļ����æ�Ÿ�����ץҩ���ʷ����������۾�
�ڿ��ʱ���ǽ�Ϲ������������и���ҩ�ĵļ۸񣬹�̨���滹��
��С�������ո����õ�ҩ�ġ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kd5",
]));

	set("objects",([
	__DIR__"npc/huoji.c" : 1,
	__DIR__"npc/doctor" : 1,
]));

	setup();
	replace_program(ROOM);
}
