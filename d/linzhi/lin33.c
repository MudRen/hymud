// Room: /d/linzhi/lin33.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
�����ڵ����������ϣ��������˵������ͺӷ紵�ͣ���ʱ��
ҡ���ţ��������һ��Ʒ��ȼ�����Ȼ�����һ����һֻ�Ŵ���
���л��գ��㼱æ˫��������ס���������������ѽ�����������
�㲻������һ���亹��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin32",
  "west" : __DIR__"lin34",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3400);
	setup();
	replace_program(ROOM);
}