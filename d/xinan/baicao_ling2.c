#include <room.h>
inherit ROOM;


void create()
{
        set("short", "�ٲ���");
        set("long", @LONG
�ٲ�����������ů�������������ƣ��ߴ����ľ�̸���ڵ��������ұڣ���
��֮�У�֦Ҷï�ܣ�����ɽ���д��У�������һ˿��գ���ɭɭ�ģ����µģ���
ʯʪ�����ģ�������С�ݺ���̦��һЩ��֪���ĳ����ڵ���������ȥ��ͷ������
���͵��ұڣ���˵ɽ���Ͽ��Բɵ������ɲ�ҩ�ġ�
LONG
        );
        set("exits", ([
                "northdown"     : __DIR__"dukou1",
                "south"      : __DIR__"baicao_ling1",
        ]));

                    
        setup();
}
void init()
{
    add_action("do_up","climb");
    add_action("do_update","update");
}
int do_update()
{return 1;}

int do_up(object me,string arg)
{
    me = this_player();
    if ( me->query_temp_marks("lin/�ڰٲ���ɽ��") )
        return notify_fail("���Ѿ���ɽ���ˣ�\n");
    message_vision("$N������ɽ������ȥ......\n",me);
    if ( me->query_xiuwei_by_type("dodge") < 1900 )
    {
        me->disable_command("verb","����������ɽ������......\n");
        call_out("fail_climbup",5,me);
    }
    else
    {
        me->disable_command("verb","����������ɽ������......\n");
        call_out("climbed_up",10,me);
    }
    return 1;
}
int fail_climbup(object me)
{
    me->receive_wound("qi",50);
    me->receive_wound("jing",70);
    me->receive_damage("qi",80);
    message_vision("$N�ո�����һ�룬ͻȻһ�Ųȿգ�ֱˤ������������\n",me);
    me->enable_path();
    me->unconcious();
    return 1;
}
int climbed_up(object me)
{
    me->receive_damage("jing",40);
    message_vision("$N�ɹ��������˶��͵�ɽ�£�\n",me);
    me->enable_path();
    me->set_temp_marks("lin/�ڰٲ���ɽ��",1);
    return 1;
}
