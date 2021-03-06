// 铁索

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "铁索");
        set("long", @LONG
一座横跨江河的铁索桥，此桥只有一道铁索，只能爬行
一上这条铁索便即晃动。
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 2 */
            "west" : "/d/guiyun/matou",
            "east" : __DIR__"taihu",
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
        if (!userp(me)) return 1;
        if(me->query("combat_exp") > 5000000) return 1;

        switch( random(5) ) {
            case 0: inv = all_inventory(me);
                    if( !sizeof(inv) ) {
                        message_vision(HIW "$N在桥上晃了一下，差点儿掉入汹涌的水中！\n" NOR,me);
                        return 1;
                    } else {
                        i = random ( sizeof(inv) );
                        if(! inv[i]->query("no_drop")) {
                           message_vision(HIW "$N在桥上一晃，身上的"
+inv[i]->name()+"掉入了水之中！\n" NOR,me);
                           destruct(inv[i]);
                           return 1;
                        }

                    }
            case 1:  return 1;
            case 2:  message_vision( HIW "$N在桥上晃了一下，差点儿掉入汹涌的水中！\n" NOR,me);
                     return 1;
            default: return 1;
        }
}

