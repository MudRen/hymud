 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�߹��鷿����һ�����ң�һ����ͨ�Ĳ�������ͨ�����ҡ�һ�Ŵ���һ
��̫ʦ�Σ����ߵ�ǽ�Ϲ���һ��������������Ψһ���ݳ�Ʒ�ǵ��ϵ�һ��
��Ƥ��һ��û��һ����ë�İ׻�Ƥ��
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"studyroom",
                        ]));
                        
        set("objects", ([
                __DIR__"npc/biehe" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
