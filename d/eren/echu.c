 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���ٺ�");
        set("long", @LONG
����ɳĮ���㵽������֮�ء����ٺӹ����ĺ�ˮ�������µĲ����·��Ź⡣��
�����Σ���ˮ˫�֣������һ֧����������ʲ�ӣ�ˮ�������Ƹ�������վ�������
�˱��ڵ��˻������ٺӵ�һ����һ��СС�ļ��У�ԭ��ֻ�Ǹ���վ��Ъ�ŵ��˶��ˣ�
�����Ϳ����˼��ҵ��̡�
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"kunlun1",
//        "southeast" : __DIR__"yangguan2",
//        "southwest": "/d/taiping/mroad1",
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
