// Room: /open/dt/lihongsanjia.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����Ǵ�ͬ������ͷ�조���֡�������ļҡ���ͷ��Ϊ�˸�
��������һ������ʵ�˵ã���˵���������ڽ����ϴ�����ʱ��
����ƾ��һ˫����ֻ������������������Ȼ���ղ��и��ˣ���
���������Ҳ������������ɳ�ƣ��������˲�����ʶ��������
��Ϊ�����ֵܣ�һʱ��Ϊ���ּѻ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huaandao2",
]));

	setup();
	replace_program(ROOM);
}
