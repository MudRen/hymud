// Room: /d/jinghai/wm17.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǿ����ɵ����Է���˯��������İ���ʮ������齣���
��������ɫ�ı��ӡ����зǳ��İ���������������͸����������
��������������ң��ݽ���¯�ﴫ��һ�������㡣����������һ
���񾲵ĸо������˲��������˯��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"wm14",
]));

	
        set("sleep_room", 1);

	setup();
	replace_program(ROOM);
}
