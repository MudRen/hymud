 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��Ѩ��");
        set("long", @LONG
����͸���������˽�����Ȼ����Ŀ���ܼ���ֻ�ж������ܣ���Բһ��
���ڵľ�������һ�н�������һƬ�ޱߵĺڰ�֮�С�û�������Ķ�����
����ǰ�ߣ�ֻ�»��׶༪�١�     
LONG
        );
        set("exits", ([ 
                "enter" : __DIR__"darkhole",
                "out" : __DIR__"whiterock",
        ]));
        set("outdoors","fengyun");
        set("coor/x",200);
        set("coor/y",-20);
        set("coor/z",40);
        setup();
} 
int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i; 
        if( userp(me) && dir == "enter" ) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->name() == "ҹ����") {
                                me->move(__DIR__"lighthole");
                                return notify_fail(HIY"\n��ӻ����ͳ�ҹ���飬����ҹ���鷢���Ĺ⣬����˶���\n"NOR);
                        }
                }
        }
        return 1;
}
