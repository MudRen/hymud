// Room: /d/fengtian/shenwu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������Ϊ��������ĵ�Ӣ�ۡ�����󽫾���Ŭ������
����������ʢ������һֱ��������λ�������ص�Ӣ�ۣ���������
�ʵ۵ĺ��������������פ�أ�һֱ�Ƕ���˹�˰����ɻ��һ֧
��װ������
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xh2",
]));

	setup();
	replace_program(ROOM);
}
