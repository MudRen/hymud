 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�Է�");
        set("long", @LONG
���������������ܹܹ���ϵ����ӡ��������Ե���Щ���ң���ȴ�������ʣ�
ǽ�������˹������޵���Ƥ�����ϰ����˸����㴼�����ƣ��ڼ�į������ֻҪ��Ը
�⣬�����˻������Ϊ����Ů��������������Ӧ�õ����ܡ���Ϊ������Ѫ�ͺ�����
���ࡣ
LONG
        );
        set("exits", ([ 
        "west": __DIR__"corridor2",
        ]));
        set("objects", ([
        __DIR__"npc/leleshan":    1,
        ]) );
        set("coor/x",-1070);
        set("coor/y",290);
        set("coor/z",0);;
        setup();
        replace_program(ROOM);
}    
