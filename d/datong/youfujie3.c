// Room: /open/dt/youfujie3.c

inherit ROOM;

void create()
{
	set("short", "�Ҹ���");
	set("long", @LONG
����Ϊ������������ʱ��Ҳ����ʵ����һ���Խ����һλ
������Ϸ������뵽��һ�����⣺��Ȼ�����־������ڽ�����
�����棬����ͽ��Ҹ��ֺ��ˡ������ֺ̣ܶ���ȴλ�ڳ��е���
�ģ��Ǵ�ͬ��������ĵش��������Ǿ������˵Ļش��ã�����
����̹�ʽ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"youfujie2",
  "east" : __DIR__"tanhuanglu2",
  "north" : __DIR__"huichuntang",
]));

	set("outdoors","datong");
	setup();
	replace_program(ROOM);
}
