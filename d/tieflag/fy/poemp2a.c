 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", HIG"̽�����¥"NOR);
        set("long", "��������������������������������������������������������������������
        ��Ҷ�Ա�ˮ���ᣬ��������������б��հ������ۡ�
        ��������ǧ���£��ٲ�һЦ����������鶽�������
        
        ˮ���������Կգ����������ϼ�У�������˼�����ء�
        ��װǳЦ������´ʸ�������Ũ����ɽ����ˮ���ݡ�
        \n"NOR                                   
        );
        set("exits", ([ 
        "east" : __DIR__"poemp2",
        ]));
        set("objects", ([
        __DIR__"npc/cici" : 1,
        ]) );
        set("resource/water", 1);
        set("liquid/container", "ˮ��");  
        set("no_practice",1);
        set("no_study",1);
        set("no_fly",1);
        set("coor/x",-10);
        set("coor/y",1);
        set("coor/z",10);
        setup();
}
/*
init() {
        int n;
        n=random(100);
        write("yes. the random(100) gives"+(string)(n)+" .\n");
}
*/                 
