 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��ǽ�����������������ź�������ĵ�̺��ǰ��������Ҳ����
�����ˣ���������һ�ȣ���ֱ������Ҥ�������ԣ������ţ�����
�����飬�����ͷ׵Ĺ�Ӱ��������������߱����أ�����������
���ɾ��� 
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                "east" : __DIR__"silver2",
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
