// Room: /d/jinghai/moon7.c

inherit ROOM;

void create()
{
	set("short", "ɽկ����յ�");
	set("long", @LONG
�ô�һ����ʯ�յء���������һ��Բľ��ˣ���������д��
��������[��������]�����Ʈ�衣�������ˮ�£�����ֵ�����
�������վ����������ࡣ����������կ�������롣������ֱ�
����ͨ���������ĸ��������ջ������������Լ���Կ���һ��
˧���ڷ���Ʈ�ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"moon6",
  "east" : __DIR__"moon10",
  "west" : __DIR__"moon11",
  "south" : __DIR__"moon8",
]));
        set("outdoors","jinghai");
        set("objects",([
        __DIR__"npc/yong1" : 3,
]));


	setup();

}
