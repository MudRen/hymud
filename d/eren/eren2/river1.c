 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��ˮ��Ȼ����壬����������Ҳ����ˮ�Ʊ����˳�ȥ����ͨһ�µ�
����һ������֮�С����Ӳ����ˮ�ֺ����̣������Ľ������ͷ�����飬
һ������һ�����������ľ��һ��һ������ˮ�е�����
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"river2",
        ]));
        set("objects", ([
//              __DIR__"npc/rat" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}    
