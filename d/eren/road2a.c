 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ɽ��");
        set("long", @LONG
ת���䣬ɽ���������ϣ�Զɽ�ǿݻ�ɫ�ģ�����Ҳ�ǿݻ�ɫ�������ɫ�Ĳ��
�£������������ض����޵������������Ҷ���ʣ����������ʱ�Ŀ��������Ʋ�֪
�����޵İ�������Ƭ��Ҷ���ɶ��£�Զ������ԼԼ��������֮����
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"valleyentry",
                "northup": __DIR__"road2b",
        ]));
        set("objects", ([       
        ]) );
        set("outdoors", "eren");
        set("coor/x",-1260);
        set("coor/y",2040);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}   
