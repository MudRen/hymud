// Room: /open/dt/roupu.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���̵�����֣�����������˵���������̳��������������
�������⣬����ʲô�ⶼ�е�������Ȼ������һ�㣬����������
Ʒ�ֻ����ǲ��٣�ʲô����ţ����Ͳ���˵�ˣ�������⡢���⡢
��Ѽ�⡢���⡢�������Ƶȵ���Ӧ�о��С�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huayanlu4",
]));

	setup();
	replace_program(ROOM);
}
