//lroad2.c

inherit ROOM;

void create()
{
        set("short","ɳ��·");
        set("long", @LONG
���ݳǵ����ɵ�,�䲻��̫ƽ���,����Ȼʮ�����֣������߷�������
���� ������·������� �ٸ�������ߺ������ͼ���˴��п���һ��·��
·������Կ���һ���߲���������Ϸ�����緢���ö���������·����һ
��ҩ�̣��������ǳ����ġ�
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
//                "north"         :       __DIR__ "yaopu",
                "south"         :       __DIR__ "fota1",
                "west"          :       __DIR__ "center",
                "east"          :       __DIR__ "lroad1",
                "north"         :       __DIR__"door",
                ])
        );
//      replace_program(ROOM);
        setup();
}

