// Room: /d/fengtian/xiaochi.c

inherit ROOM;

void create()
{
	set("short", "С�Ե�");
	set("long", @LONG
���ֽ��ϵ����С�Ե����������Ϊ����ļ��������ʢ��
���Ҳ����ڶ��ݣ�ʵ���ǺóԵĲ����ˣ���Ȼ�����洫�����ա�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ll3",
]));

	setup();
	replace_program(ROOM);
}
