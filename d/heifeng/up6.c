// Room: /d/heifeng/up6.c

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
  "west" : __DIR__"up5",
  "north" : __DIR__"up9",
  "south" : __DIR__"up3",
]));

	set("outdoors","heifeng");

	setup();
}
