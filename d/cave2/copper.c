 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ͭ��");
        set("long", @LONG
��ʽ�����ı��������и�ʽ�����İ���������֮������������
ɭɭ�ĺ��⣬���ıڶ��ճ�������ɫ��ǹ����ĳ����ɰˣ���
�̵ĲŲ������ߣ�������������ľ������С�ľ�������ӡ���
ǹ�̽�������������ţ�������Ȼû��������ȴ�����̺���ɱ����
���˵�����ɱ����
    ����֮�£����е���ɱ֮����ֻ�¾���������� 
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
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
