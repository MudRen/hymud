// Room: /d/jinghai/moon17.c

inherit ROOM;

void create()
{
	set("short", "ˮկ���̨");
	set("long", @LONG
�߸ߵķ��̨������ˮկ�����ܵе�Ҫ�أ����۰����ҹ��
��ˮ�����ְ�ֵ�أ����е��飬���Ǳ��ȼ����̨�м�ѷŵ�
���Ƿ�֪ͨˮ������׼�������ﻹ�и���ʯ������ˮʦ����ʱ��
���԰����ﵱ����̨�ֵ����˵Ľ����������Դ�ˮկ����������
���Ǿʹ�δ��ʹ�ù���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"moon27",
  "north" : __DIR__"moon10",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
