// Room: /open/dt/zhubaodian.c

inherit ROOM;

void create()
{
	set("short", "�鱦��");
	set("long", @LONG
����һ�Ҳ��õø����ûʵ��鱦�꣬��̨���ʽ����������
��ʯ���ݶ��ϵ��ŵĲ�˹�����ƽ����ӳ��ʹվ�ڹ�̨�ߵ�һλ
Ů�ɻ���ɢ����һ����������������ʡ����������Ů����Ϊ
ʲô���鱦ʤ��һ�е�ԭ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tanhuanglu1",
]));

	setup();
	replace_program(ROOM);
}
