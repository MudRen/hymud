 inherit ROOM;
void create()
{
        set("short", "�ر���");
        set("long", @LONG
˵�ǲر��ң�ȴ�ǿտյ���ʲô��û�У������󿪵Ĵ����Ӷ��ڽ���
������м��������ߵ����飬�ƺ�ͻȻ����ʲô��ʣ����˴������е�
�䱦�뿪�����
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"mouseroom3",
                
                        ]));
        set("objects", ([
                __DIR__"npc/rat2" : 3,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
