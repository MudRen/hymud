 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ͭϿ");
        set("long", @LONG
��ͭϿλ�ڶ�ɽ֮�䣬����ţ��ɽ����Ϊ����ɽ�����ٺӴ��д�Ͽ��������ɫ
���Ρ�������������һ���������������һ���졢ħ�ߡ�˯��ɽ�����ſڡ�ֻ�Ǵ�
���˼��������������У�ԭ��ס�ŵļ����˼Ҳ������ѣ��׷�Ǩ��������·��ֻʣ
��Щ��ԫ�ϱڡ�
LONG
        );
        set("exits", ([ 
                "northwest" : __DIR__"shike",
                "northeast" : __DIR__"deserted",
                "south": __DIR__"kunlun1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
