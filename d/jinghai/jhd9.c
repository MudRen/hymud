// Room: /d/jinghai/jhd9.c

inherit ROOM;

void create()
{
	set("short", "��������ۡ����");
	set("long", @LONG
�����Ǿ������������ţ���ڵĴ������ҳ��������Ϸ�����
һ��ڵ׽��ֵĺ��ң����� �������� �ĸ��������֣���˵����
���������д�ģ��ּ��䲻ʮ����������һ��һ��ȴ�Ǽ�������
������ɭ�ϣ��ɴ˿��Կ�����д֮�˱���һλ���мױ��ĺ���֮
ʿ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"jhd8",
  "west" : __DIR__"jhd10",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
