 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���Ǹ�");
        set("long", @LONG
ʮ��ǰ���ϳ��˸����ˣ��뾩ǰ��������˸�������ү����������˻�û����
���ϣ��ͱ�ǿ�������Դ����Ӵ���û�˹�ˡ��Դ����������������ͳ�������
�����ǺȾ�ȡ�֣�����ˤ�ӱ���ĳ�����
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"nstreet3",
        ]));
        set("objects", ([
         __DIR__"npc/nangong":     1,

                
        ]) );
        set("coor/x",-1115);
        set("coor/y",210);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
