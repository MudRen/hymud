// Room: /d/heifeng/ling1.c

inherit __DIR__"up.c";

void create()
{
	set("short", "�ڷ���");
	set("long", @long
�����Ǻڷ�ɽ���ʵ�ɽ�붥�˵�һ��Сƽ̨��ƽ̨��Χ����
һЩ��ݣ�������˵�����������(cai)������֥������Ĳݴ���
��һ����ֱ��С·ͨ�����档
long
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"up2",
  "north" : __DIR__"up4",
]));

	set("outdoors","heifeng");

	setup();
}
