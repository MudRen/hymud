 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���ٺ�");
        set("long", @LONG
����ɳĮ���㵽������֮�ء����ٺӹ����ĺ�ˮ�������µĲ����·��Ź⡣��
�����Σ���ˮ˫�֣������һ֧����������ʲ�ӣ�ˮ�������Ƹ�������վ�������
�˱��ڵ��˻������ٺӵ��ϲ���һ��СС�ļ��У�ԭ��ֻ�Ǹ���վ��Ъ�ŵ��˶��ˣ�
�����Ϳ����˼��ҵ��̡�
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"kunlun2",
                "southeast" : __DIR__"yangguan2",
                "southwest": "/d/taiping/mroad1",
                "south":        __DIR__"echu",
		"north": "/d/taiping/swamp2",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "eren");
        set("coor/x",-990);
        set("coor/y",140);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
