// Room: /open/dt/kongzici.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ����Ϊ���ϵĿ�������ԭ��Ϳ�ɺ�ɫ��ǽ���Ѿ��߲�
�����ˣ�Ժ��һ���ϰ�������ĹŰ��������չ������֦�⣬����
����Ҷ����ʯ��������ƬƬ��Ӱ���������ʢ����ʱ��һ������
���������еĿ�ʥ��ǰ����Ħ�ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"huaandao3",
]));

	setup();
	replace_program(ROOM);
}
