//tingyuan.c

inherit ROOM;

void create()
{
        set("short","ͥԺ");
        set("long", @LONG
���Žྻ��ͥԺ,����ʯ�̵�, ���Ϻ������Ǹ���һ�øߴ�ĹŻ�,��
��֦�ɴִ�,֦Ҷï��,������ס������Ժ��,�������Ҷ�ķ�϶������,��
��ʯ����������Ʈ��������Ӱ��.����ɮ������ֻɨ��,���ڴ�ɨͥԺ. ��
������Ǵ��,���Ҹ���һ���᷿.
LONG
        );
        
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "shanmen",
                "north"         :       __DIR__ "dadian",
                "west"          :       __DIR__ "er1",
                "east"          :       __DIR__ "er2",
                ])
        );
        set("objects",([
            __DIR__"npc/monk" : 1,
        ]) );
//      replace_program(ROOM);
        setup();
}

