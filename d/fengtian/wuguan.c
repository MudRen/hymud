// Room: /d/fengtian/wuguan.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��������ǵ���Ŭ������Ϊ���ᳫ�����䡱����������
ͬ��ʦ����ʢ��������ݣ����ڱ������䣬��ʵ�в����˼ҽ���
�����ӵ�����ѧϰ�书ǿ���塣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wy3",
	"north" : __DIR__"wuguan2",
]));

	setup();
	replace_program(ROOM);
}
