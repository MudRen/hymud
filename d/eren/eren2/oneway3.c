 inherit ROOM;
void create()
{
        set("short", "һ����");
        set("long", @LONG
�����ϣ���·������Ţ�������ֽŲ��ã������ϵεδ���������ˮ��
����������С�꣬����������¡¡֮����������������ǧ�������ڸߴ���
�ڡ�����Խ��Խǿ����ǿ�ز���ˮ��
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"oneway2",
                //"westup" : __DIR__"oneway4",
                        ]));
        set("outdoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
