// Room: /d/jinghai/moon24.c

inherit ROOM;

void create()
{
	set("short", "�����װ���");
	set("long", @LONG
ǿ���ĺ��紵�÷���ֱ�Σ��㲻��һ�����ģ�����������
ȥ������һ��˫Φ�촬�����Ĵ�ͷ���޳��Ĵ������һֻľ��
�����ǳ���ϸ��������ֻ���������������׷�������ĺ��١���
��û���κα�־���ƺ�����ˮկ��Ĵ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"moon16",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
