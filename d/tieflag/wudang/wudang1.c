 inherit ROOM;
void create()
{
        set("short", "����ǰԺ");
        set("long", @LONG
��Ժ����������������������Ե��䵱�ɵ���ʷ�ƾá���ʯ����
�ɵĵ��棬����������ĺۼ�����Ժ�ľ�ͷ�Ǽ�������ʯ̨�ף�����
̨�׾����������������������һ����ʯС·��ͨ�����档
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"zhixiao",
                "west" : __DIR__"lingxuyan",
                "northeast" : __DIR__"wuroad1",
                "out" : __DIR__"wudang",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",100);
        set("coor/y",-140);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
} 
