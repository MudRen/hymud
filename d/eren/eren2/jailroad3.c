 inherit ROOM;
void create()
{
        set("short", "�ص�");
        set("long", @LONG
����Ѳ���˵�ǵ�·��ֻ��һ����ʪ�ֻ��ĵص��������ܵͣ�������
����ͨ��������������Ҷ����ڹ�¡�˵ز�֪��ǳ��û��һյ�ƣ�û��һ
�����죬����ϤϤ����������С����ܹ���ż���ȵ�������֨��һ����С�
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"jailroad2",
                "northwest" : __DIR__"jailroad4",
                "west" : __DIR__"guardroom",
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}     
