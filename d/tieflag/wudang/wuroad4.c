#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "��Ժ��");
        set("long", @LONG
��ʯС·�����˻��ԣ�������Ϊֹ��һ��СС�����������ڴ˴���
���ϵ�ǽ���Ͽ�������Ժ�������֡����Թ���һ��ľ�ƣ���д������
�����ӣ��������룡��
LONG
        );
        set("exits", ([ 
                "enter" : __DIR__"wudang3",
                "west" : __DIR__"wuroad3",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",140);
        set("coor/y",-130);
        set("coor/z",50);
        setup();
} 
int valid_leave(object me, string dir)
{
        int i;
        object *inv, ro; 
        if( dir != "enter" ) return 1;
        if( !me->query_temp("marks/͵"))  {
                me->set_temp("marks/����", 0);
                return 1;
        } 
        message_vision(HIY "�������������м���������У�������ѽ����ץ��ѽ����\n"NOR, me);
        message_vision(HIR "�������ˡ���һ����$N���Ժ������صش���һ����\n"NOR, me);
        me->unconcious();
        message_vision(HIY "���������ʿ��$N���еĶ�������һ�顣\n\n"NOR, me);
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                destruct(inv[i]);
        }
        message_vision(HIY "���������ʿ��$Ņ�˳�ȥ��\n"NOR, me);
        me->set_temp("marks/͵", 0);
        me->set_temp("marks/����", 0);
        ro = find_object(__DIR__"road1");
        if(!objectp(ro)) load_object(__DIR__"road1");
        me->move(ro);
        message("vision", HIY "���������ʿ��" + me->name() + "���ص�ˤ���˵��ϣ�Ȼ��ת���뿪�ˡ�\n"NOR, environment(me));
        return notify_fail("������������\n");
}       
