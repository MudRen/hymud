// muqiao.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "ľ��");
	set("long", @LONG
����һ�����ʧ�޵���ľ�ţ��ɼ��������������ɡ�����ĺ�ˮ���Խ�
�ɼ������������ɽ��ѩ�ڻ��㼯�ɵ�һ����������ˮ������Ϣ���Ӱ�����
��һ�����������ѳɵĳ�ǽ���ܶദ����̮����
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([
		"south" : __DIR__"hean2",
		"north" : __DIR__"hean1",
		"east" : __DIR__"shilu6",
                "west" : "/d/ruzhou/xiaozheng",
	]));

        set("objects", ([
               "/clone/npc/npc1" : 1,
        ]));

	setup();
	replace_program(ROOM);
}
