 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
һ�Ų���ȥ����Ȼ�������֣�ԭ��ʯ·�ѵ��˾�ͷ��·�Ե��������
��ֻ࣬����ϡ�����������һ��С�ı㱻ͻ�����ҽ�ײ��ͷ�����Ժ���
���з�ι���������񻹴���ˮ���� 
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"court1",
                "southup" : __DIR__"exit2",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
