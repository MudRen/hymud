 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
һ���ƾɵ����ӣ�����ȴ��Ϊ��ª�������ﵽ�������Ż�
�������������û�����������������ڷ���Ʈҡ����Щ��
���ȱ��紵���ˣ�֩����æ�������»��� 
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"yongdao7",
                "east" : __DIR__"yard2",
                
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
