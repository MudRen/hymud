// minju1.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����é�ݴ�ķ��ݣ�����򵥵İڷ��ż��ž����Σ����ݱ�
��ɨ��һ����Ⱦ��һ��Ů���������ұ߿�ǽ�İ����Ϸ첹���·�������
ʱ��ͣ�����еĻ�����̽ͷ��������ȥ���������ڵ���ʲô�ˡ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"xiaoxiang",
        ]));

	set("sleep_room", 1);


        set("objects",([
		__DIR__"npc/chunhua" : 1,
	]));

        setup();
        replace_program(ROOM);
}
