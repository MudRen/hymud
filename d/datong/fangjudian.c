// Room: /open/dt/fangjudian.c

inherit ROOM;

void create()
{
	set("short", "���ߵ�");
	set("long", @LONG
����һ��ר�����ۺͶ������ߵĵ��̣���˵���ǵı����õ�
���ס�ͷ��ȫ���Ǵ�������ȥ�ģ���͢������Ŀ��׸���������
����ǧ�������ͻ˺ɱ��ʱ��һ���õ����׿ɾ��Ǳ�ʿ�ǵ�
��������������кܶ���ص�������ʿ�������ﶩ������ķ��ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jinyangjie2",
]));

	set("objects",([
	__DIR__"npc/armorboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
