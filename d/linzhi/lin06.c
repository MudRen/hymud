// Room: /d/linzhi/lin06.c

// Room: /d/linzhi/lin05.c

inherit ROOM;

void create()
{
	set("short", "�һ���");
	set("long", @LONG
�������һ�����ֻ����������Ұ��������������һƬ��Ȼ��
���֣���֪�Ӻ�ʱ���еġ�ÿ�굽�˰������ӳ���ļ��ڣ�����
���������ժ��������ӡ��ݵ������˽��������������ʹ͸���
��ġ����������ţ���Ȼ������ʧ�˷���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin05",
  "west" : __DIR__"lin07",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}


