 inherit ROOM;
void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵĻ�Ұ�أ�ɽ�Ƶ�������ͻȻ���ĵ����������಻��
������������ȥ��ɳĮ�Ļ���С·������������ԶԶ������������֮һ��̩ɽ
���ڣ����͵�ɽ��ֱ��������Ρ��׳����
LONG
        );
    set("exits", ([ 
        "north" : __DIR__"roadp",
                "southup" : __DIR__"chenxiang3",
        "northwest" : "/d/taishan/taishanjiao",
        ///"northeast" : "/d2/shanxi/road",
        ]));
        set("outdoors", "chenxiang"); 
        set("coor/x",-510);
        set("coor/y",-430);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}    
