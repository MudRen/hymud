 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
�����ϣ���·������Ţ�������ֽŲ��ã������ϵεδ���������ˮ��
����������С�꣬����������¡¡֮����������������ǧ�������ڸߴ���
�ڡ�����Խ��Խǿ����ǿ�ز���ˮ��
LONG
        );
        set("exits", ([ 
                "southdown" : __DIR__"exit2",
                "southup" : __DIR__"exit",
                        ]));
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
