// Room: /open/dt/dangpu.c

inherit HOCKSHOP;

void create()
{
	set("short", "����");
	set("long", @LONG
�ſڵĲ�����������д��һ�����ġ������֣�ʹ�˿��˾�
��������߽�������һ�������Ĺ�̨�ѷ���ֳ����룬��̨����
��һ�����Ű��ֺ��ĳ����������һ�����������ӵ���˵����
������������Ȼ�������ᣬ����ɫ���Ǻܺã������־����ƣ���
��ֻ��ֵʮ�����ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huaandao2",
]));

	set("objects",([
	__DIR__"npc/pawnboss" : 1,
]));

	setup();
}
