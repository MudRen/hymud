#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "��ջ˯��");
        set("long", @LONG
��ջ��һ��˯��������ɸɾ�����һ�Ŵ󴲣�����������Ϣ˯���������и���
�ˣ���ͷ����ģ�����ȥ�����ˡ����䴰�����ţ�������Ǽ�����Ľֵ���
LONG
        );
        set("type","house");
        set("exits",([
                "down":__DIR__"kezhan",
        ]) );
        set("objects",([
                __DIR__"npc/xianggong" : 1,
        ]));
        set("coor/x",-590);
        set("coor/y",120);
        set("coor/z",10);
        setup();
} 
void init()
{
        object me; 
        if( interactive(me = this_player()) ) 
        {
                call_out("greeting", 1, me);
        }
} 
int greeting(object me)
{
        object room; 
        if( userp(me) && me->query("age")<16 )
        {
                room = find_object("/d/fugui/xiaojie1");
                if(!objectp(room)) 
                        room = load_object("/d/fugui/xiaojie1");
                message_vision(HIY"ͻȻ������$NĪ������ı��˴Ӵ����ӳ�ȥ������\n"NOR,me);
                me->move(room);
           me->receive_damage("qi",50);
                message_vision(HIY"$N������������ֹ�����˭�ҵ�С������ôС��ȥ���ֵط���������\n"NOR,me);
        }
}      
