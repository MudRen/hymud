// Room: /d/heifeng/up2.c

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
  "east" : __DIR__"up3",
  "west" : __DIR__"ling1",
  "north" : __DIR__"up5",
  "southdown" : __DIR__"ling2",
]));

	set("outdoors","heifeng");

	setup();
}
