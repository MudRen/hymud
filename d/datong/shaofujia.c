// Room: /open/dt/shaofujia.c

inherit ROOM;

void create()
{
	set("short", "�ٸ���");
	set("long", @LONG
����һ����ɨ�÷ǳ��ྻ��Ժ�䣬�������������߷�������
����һ��ƫ����Ժ�ӽ�����ͣ��һ���󳵣�һֻ�������ڵ�ͷ��
��ʳ����Ĳ��ϡ��߽����У�һ�����ڸ�����Ӥ��ι�̵��ٸ�Ц
��˵����ɽ�������������ɰ�����������̧ͷ������ʱ������
��Ц�ݵ�ʱתΪ���ȣ����æ���˳�ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"luzhuxiang2",
]));

	setup();
	replace_program(ROOM);
}
