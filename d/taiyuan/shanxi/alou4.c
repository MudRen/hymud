inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "����"); 
    set("long", @long
�ź��м�ʮ��ʯ�ף�ͨ��صף�������ɽ������û������ȥ�ѿ���
��һƬ��ⱦ����ɽ���ǿյģ���Բ��ʮ�ɶ��������ĺ�ӣǹ��һ����
�Ĺ�ͷ��������һ����Ļƽ��鱦��������ͨ�������У�������Ҳû��
��������ô��ĵ�ǹ���鱦��
long 
    ); 
    set("exits", ([ 
    	//"east" : __DIR__"midao", 
    	//"south" : __DIR__"midao",
    	//"west" : __DIR__"midao",
    	"enter" : __DIR__"alou5",
        ])); 
                set("objects", ([
                __DIR__"npc/wang1": 1,
                __DIR__"npc/wang2": 1,
                __DIR__"npc/wang3": 1,
                __DIR__"npc/wang4": 1,
        ]));
        set("no_fight",1);
        set("no_magic",1);
        set("NONPC",1);
        set("valid_startroom",1);
    set("indoors","shanxi"); 
set("coor/x",-400);
        set("coor/y",-250);
        set("coor/z",99);
        setup(); 
                create_door("enter", "ʯ��", "out", DOOR_CLOSED); 

} 