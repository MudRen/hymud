// Room: /d/paiyun/ting.c

inherit ROOM;

void create()
{
	set("short", "�ɸ�ͤ");
	set("long", @LONG
����һ��̽��ʯ̨��Сͤ�ӣ�ͤ���������������£�������
����������û�뵽�������ﻹ����ôһ���þ��¡�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu6",
]));
        set("objects", ([
                "/kungfu/class/taohua/lu2" : 1,
        ]));
	set("outdoors", "paiyun");

	setup();
	replace_program(ROOM);
}
