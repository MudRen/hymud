 inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
����������ɽ��Ψһ��һ��С��С���Ǻܴ󣬵�ȴ�ܷ�����
����������ɽ�ţ����м�ʹ����Сͯ��Ҳ�Ἰ��̫��ȭ���������С
�򣬾����䵱�ɵ���һ��Դ�ء�����ɽ��
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"xzroad1",
                "north" : __DIR__"bwuroad2",
                 "southeast" : "/d/taoyuan/taolin",
        ]));
        set("outdoors", "wudangfy");
        set("objects", ([ 
                __DIR__"npc/xiaotong": 2 
        ]) );
        set("coor/x",100);
        set("coor/y",-30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
