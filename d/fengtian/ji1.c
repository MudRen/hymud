// Room: /d/fengtian/ji1.c

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", @LONG
��ʹ�ں���Ķ�����Ȼ�����ٲ�����ɫȮ������Ժ�ش���
����ȻҲ��������¡������Ժ�Ķ�¥�ǰ������в��ٲ�ɫ˫ȫ��
���ˣ���˵������Ӿ�������һλ�����ˣ���֪����û�и���
��������
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wy5",
]));

	set("objects",([
	__DIR__"npc/mama" : 1,
]));

	setup();
	replace_program(ROOM);
}
