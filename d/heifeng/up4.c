// Room: /d/heifeng/up4.c

inherit __DIR__"up.c";

void create()
{
	set("short", "�ڷ���");
	set("long", @LONG
�����Ǻڷ�ɽ���ʵ�ɽ�붥�˵�һ��Сƽ̨��ƽ̨��Χ����
һЩ��ݣ�������˵�����������(cai)������֥������Ĳݴ���
��һ����ֱ��С·ͨ�����档
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"up5",
  "south" : __DIR__"ling1",
  "north" : __DIR__"up7",
]));

	set("outdoors","heifeng");

	setup();
}
