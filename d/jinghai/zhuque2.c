// Room: /d/jinghai/zhuque2.c

inherit ROOM;

void create()
{
	set("short", "��̲��");
	set("long", @LONG
ֻ����ǰһ����ο��ɫ�Ĵ���׺������ʯ�ĵ�̺������
��ͷֱ�̵���Ľ��£����ڽ�ɫ��ɳ̲�ϣ����������µĴ�����
ζ�Ŀ������������һƬ������ֻ���������ķ���ȫ��һɨ����
����Ŀ��ȥ�����쾡ͷ�������޵ļ���С�����㲻����ȥ��һ��
�����ǲ��Ǵ�˵�е������ɾ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"zhuque3",
  "northwest" : __DIR__"zhuque5",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
