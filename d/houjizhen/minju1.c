// minju1.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ľͷ��ķ��ݣ���ͽ�ıڣ��ݽǵ��׸��ǿյģ�������
��ˮ��Ҳ�ǿյġ�����ȱ�첲���ȵ����ο�ǽ���š����������Ѿ�����
����ֵǮ�Ķ���ȫ�������ˡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"shilu5",
        ]));

	set("objects", ([
		"/clone/npc/man" : 1,
	]));

        setup();
        replace_program(ROOM);
}
