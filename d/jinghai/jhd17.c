// Room: /d/jinghai/jhd17.c

inherit ROOM;

void create()
{
	set("short", "�ı���");
	set("long", @LONG
�����Ǿ����������ı������󲿷ݸ��صľ���������Ҫ����
����ܾ��ӵ�ѵ������������һ���±��ڽ���½�Ϲ���ѵ������
��Ҳ�Ǿ�����һ��һ�ȴ��ı��ĵط�����ʯ�̾͵Ĳٳ����±���
̤�ù⻬�ޱȣ�������һ���������������߾��ǹ������鷿��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"jhd11",
  "west" : __DIR__"jhd19",
  "south" : __DIR__"jhd16",
]));
        set("objects",([
        __DIR__"npc/shuishou" : 4,
        __DIR__"npc/jiading" : 4,
]));

        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
