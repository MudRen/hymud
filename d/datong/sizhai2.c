// Room: /d/datong/sizhai2.c

inherit ROOM;

void create()
{
	set("short", "˽լ");
	set("long", @LONG
������һ�������ûʵ�סլ����ڵĴ������ս����ţ�͸��
һ������֮����������һ����Χס�ŵ��˼ң������Ƕ���֪����
��λ��ٹ���ס�ڴ˴�����������ƬլԺ�����ƣ�����ס������
�Ĳ��ǲƴ����ֵ����˱��������кպ����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huayanlu5",
//  "north" : __DIR__"zhai2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shaonian" : 1,
]));

	setup();
	replace_program(ROOM);
}
