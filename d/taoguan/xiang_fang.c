#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "���幬�᷿");
        set("long", @LONG
����ķ��䣬ȴ�ܸɾ�����������ǽ�Ϲ��ż���ɽˮ����
�����Ǽ��Ŵ�齣�������ʿ���ڴ����������ǽ�Ϲ��ż��ѳ�
�������Կ������Ƕ��Ǻý���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"da_yuan",
]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/reg_taoist" : 2,
                __DIR__"npc/up_taoist" : 1,
                __DIR__"npc/m_taoist" : 1,
                __DIR__"npc/m_taoist" : 1,
                __DIR__"npc/huo" : 1,
]));
        set("coor/x",-30);
        set("coor/y",2100);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}
