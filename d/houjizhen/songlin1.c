// songlin1.
// by dicky

inherit ROOM;

void create()
{
        set("short","����");
        set("long", @LONG
������һƬïʢ�����֣����о����ĵģ�����������䣬ң��ͺ�����Ϊ���
�������������˼������ء����Ϸ���һ��С·��ͨ�����ķ���
LONG
        );

	set("outdoors", "houjizhen");

        set("exits", ([
                "southeast" :__DIR__"lzxiaolu",
                "northeast" :__DIR__"songlin2",
        ]));
        
        setup();
        replace_program(ROOM);

}

