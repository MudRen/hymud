// Room: /d/fengtian/hua.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���СС�Ļ���Ϊ�»�·�����˲��ٵľ��£��߽��������
һ�����µĸо������˻��㻹�л������ഺ����Ϣ�������˻���
���ϰ��Ǹ���Ư����С���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xh3",
]));

	set("objects",([
	__DIR__"npc/flower_sell" : 1,
]));

	setup();
	replace_program(ROOM);
}
