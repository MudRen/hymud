// paifang.c
//by dicky

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "�Ʒ�");
	set("long", @LONG
�����Ǻ����Ʒ����������ͽ������ˣ��������ϡ�٣�
���������˻ҳ����Ե��ƾɲ�������С�����������뿪�ⲻ��֮�ء�
�Ʒ�����������д�ż�������"���"��ǽ�������ż��Ÿ�ʾ������
����һЩ���񼫵�ͨ�������������µ����ţ�������ּ�����ÿ�
ʼģ����
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"west"  :  __DIR__"shilu1",
		"east"  :  __DIR__"tulu2",
	]));

	setup();
	replace_program(ROOM);
}
