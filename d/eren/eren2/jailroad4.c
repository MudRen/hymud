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
                "southeast" : __DIR__"jailroad3",
                "north" : __DIR__"jailroad5", 
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
