 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ʯ�����");
        set("long", "
һ�붴�����Ǳ���һ�����󣬶����ϼ��������Ƶ�ţ�;���������յ������õģ�
��������ʯ�̳ɵģ������˾��ȵ��ǣ�����ʯ��Ȼ��������һ��������������
����������ֲֳ棬����ִ�ޡ�����ǰ��һ��������б����������ͷ�м���
��Ӱ�ζ���\n"
        );
        set("exits", ([ 
                "northdown" : __DIR__"yongdao1",  
                "down" : __DIR__"tocave",  	
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
