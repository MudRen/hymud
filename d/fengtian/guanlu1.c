// Room: /d/fengtian/guanlu1.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����·������ʢ�����ź���Զ·�Ĺٵ�������û����������
ô���������ӣ��ٵ����в��ٽ��Ǻͳ��ǵ��ˣ�������ԶԶ����
����ʢ���ǵ������ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"w_gate",
  "east" : __DIR__"wy1",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
