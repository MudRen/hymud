 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "Сʯ��");
        set("long",  @LONG
����ʯ����һ�鰼���ĵط���Լ�������ɼ���������һյ�͵ƣ�����
����ľ���һ�Ŵ������Ϻ��Ҷ��ż�������������ȥ����ڿ���
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"yongdao3",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}       
