 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����ɽׯ");
        set("long", @LONG
ɽׯ�����һ�ٶ�ʮ�Ű�������ÿ�����Զ������˿��ˣ�ֻ�ǣ�ÿ�����˶�����
�������ŵ�����������ӡ��ƺ�������ʲô����֮�¡�������ͷ���ĸ��ˣ�����
������裬�ں��Աߵ�Ů������˽�
LONG       );
        set("exits", ([ 
                "west": __DIR__"yuanvillage2",
               "east": __DIR__"yuanvillage3",
                "south": __DIR__"yuanvillage3",
                "north": __DIR__"yuanvillage3",
        ]));
        set("objects", ([
                
        ]) );
set("coor/x",-1090);
        set("coor/y",195);
        set("coor/z",0);

        setup();
        //replace_program(ROOM);
}       
