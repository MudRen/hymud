// Room: /d/fengtian/xf1.c

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
�ɻ����ͨ���򱱾͵�������᷿���᷿�ǻʵ�С�ĵط�
����ʰ�ķǳ����£�����Ҳ��ʵ۵��鷿�ˣ��ʵ�ʱ���������
��һЩ��Ҫ�Ŀ��ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jjf3",
]));

	setup();
	replace_program(ROOM);
}
