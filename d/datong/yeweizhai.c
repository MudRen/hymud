// Room: /open/dt/yeweizhai.c

inherit ROOM;

void create()
{
	set("short", "Ұζի");
	set("long", @LONG
����������ر�����Ϊ����Ұζ��ʦ����˵��ǰ�ǻʹ�
���������ר�Ÿ��ʵ�����Ұζ�ģ������˻��˺ܴ�Ĵ��۰���
�ӻʹ���������������ͨ���ϰ���Ҳ�ܹ��Ե���ζ���ѵ�Ұζ
�ˡ������Ұζȫ���ǳ����һ��������ϲ�������ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"youfujie2",
]));

	setup();
	replace_program(ROOM);
}
