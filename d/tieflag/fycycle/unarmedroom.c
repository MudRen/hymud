#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ȭ��");
        set("long", @LONG
��һ�߽������ӣ�����һ�ɺ���֮������������������д�����ȫ��ʯ�ƣ�
�ı�Ҳ������ʯ���̣����Ϲ���һ�����ƣ��Ա�����һ�����ң�ʯ���Ϸ���һЩ
�鼮��������עĿ���������и��������ĵ����ܵ���һ����ȭ�ĵ��ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "center" : __DIR__"groundroom",
        ])); 
        set("objects", ([
               __DIR__"npc/unarmedbook" : 1,
                        ]));
        set("indoors", "fengyun");
        set("coor/x",-160);
        set("coor/y",50);
        set("coor/z",0);
        set("no_magic",1);
        set("no_spell",1);
        setup();
}       
