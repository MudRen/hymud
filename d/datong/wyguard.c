// Room: /open/dt/wyguard.c

inherit ROOM;

void create()
{
	set("short", "��Զ�ھ�");
	set("long", @LONG
��Զ�ھֹ�ģ�����Ǻܴ�����ͷ��ȫ̩�Ǹ��Ͻ����ˣ���
�����з���ʮ�����ˣ���Ȼû�б���ʲô�ܹ��ص��ڣ�������Ҳ
û��ʧ���֣�����������������ͬ����Ŀ�����Ҫ������Щ��
�����ڵ�ȥһ�㶼�͵���Զ�ھ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"tanhuanglu3",
]));

	setup();
	replace_program(ROOM);
}
