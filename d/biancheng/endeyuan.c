 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����Ԫ");
        set("long", @long
������Ԫ�������沢����װ��Ҳ�����������������ſ�Ƥ����ͺ���Դ���
ͦ����վ���ſڵ���ػأ����ǿ�����ơ���������Ľ���������û�е�����
��Ԫ��������ػغ��������ͺ�������е㲻����˼��
long

        );
        set("exits", ([ 
        
        "north": __DIR__"road3",
        
        ]));
        set("objects", ([
         __DIR__"npc/mahuihui":     1,
        ]) );
        set("indoors", "biancheng");
        set("coor/x",-1120);
        set("coor/y",175);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
