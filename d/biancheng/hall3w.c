 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����������");
        set("long", @LONG
����˭��һ�ۿ����������������Ҫ��һ����������Ȼֻ������ʮ���ɿ�����
ֱ���������޷�����һ������Ҫ���ſ��ߵ���һ��ȥ��˵����Ҫ����һ��ǧ����
������ߵ�ǽ�ϣ����ŵ����������ڣ��е�������˻���еķ������㣬ÿƥ������
̬����ͬ��ÿƥ�������ֵ��������������ޱȡ�
LONG
        );
        set("exits", ([ 
        "east": __DIR__"hall3",
        ]));
        set("objects", ([
                //__DIR__"npc/leleshan":  1,
        ]) );
        set("coor/x",-1120);
        set("coor/y",310);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 