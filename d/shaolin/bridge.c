// ����

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ����罭�ӵ������ţ�����ֻ��һ��������ֻ������
һ�����������㼴�ζ���
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"hanshui1",
            "north" : __DIR__"hanshui2",
        ]));
        set("no_clean_up", 0);

        setup();
}

int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i;

        if(wizardp(me)) return 1;
        if(me->query("hyvip")) return 1;
        if(me->query("combat_exp") > 5000000) return 1;
if (!userp(me)) return 1;
        switch( random(5) ) {
            case 0: inv = all_inventory(me);

                    if( !sizeof(inv) ) {
                        message_vision(HIW "$N�����ϻ���һ�£�����������ӿ��ˮ�У�\n" NOR,me);
                        return 1;
                    } else {
                        i = random ( sizeof(inv) );
                        if(! inv[i]->query("no_drop")) {
                           message_vision(HIW "$N������һ�Σ����ϵ�"
+inv[i]->name()+"������ˮ֮�У�\n" NOR,me);
                           destruct(inv[i]);
                           return 1;
                        }

                    }
            case 1:
            case 2:  message_vision( HIW "$N�����ϻ���һ�£�����������ӿ��ˮ�У�\n" NOR,me);
                     return 1;
            default: return 1;
        }
}

