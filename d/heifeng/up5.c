// Room: /d/heifeng/up5.c

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
  "east" : __DIR__"up6",
  "west" : __DIR__"up4",
  "south" : __DIR__"up2",
  "north" : __DIR__"up8",
]));

	set("outdoors","heifeng");

	setup();
}
