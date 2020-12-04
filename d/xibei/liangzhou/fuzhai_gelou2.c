//fuzhai_gelou2.c ��¥
//Hydra

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","��¥");
    set("long", @LONG
��¥�Ķ�¥��С���˯����ɢ�������˵�������һ�Ź봲�������棬��ʵ�
������ǰһ�������Ϸ����ķ��ı����Ա߰ڷ���һ���١�ǽ���Ϲ���һЩ�黭��
����С���Լ�д�ġ�
LONG
    );
    set("exits", ([ 
        "down"            :       __DIR__"fuzhai_gelou",
    ]) );
    set("objects",([
        __DIR__"npc/xiaojie"    :   1,
    ]) );

    setup();
}

void init()
{
    add_action("do_lie",({"lie","tang"}));
}

int do_lie( string arg )
{
    object ppl = this_player();
    int i;
    object env,*ob;
    
    //if ( !ppl->query_temp("����/can_lie") ) return 0;

    env = environment(ppl);
    ob = all_inventory(env);
    for ( i=0;i<sizeof(ob);i++ )
    {
        if ( !ob[i]->is_character() )
            continue;
        else if ( ob[i] == ppl )
            continue;
        else
            return notify_fail("����������̫���ˣ��㻹���������ȶ��������ɡ�\n");
    }
    
    message_vision(CYN"$N�ߵ�С�㴲�ߣ��ҿ��屻��ЬҲ���ѣ�������ľ�����\n"
"������ı���֮�ϡ�\nȻ����ϳ񱻣�����ɴ�ʣ�Ϩ����򣬷�������ԡ�\n"NOR,ppl);
    ppl-> disable_command("verb","�㻹�����ڴ��ϲ�Ҫ���������⾪��������\n");
    call_out("rascal_come",10,ppl);
    return 1;
}
        
void rascal_come( object ppl )
{
    string msg;
    msg = GRN"ԼĪ����һ�����Σ���ֻ�����š��ġ���һ������԰��Ͷ��һ��ʯ��\n";
    msg +=   "��������Ƭ�̣�Χǽ��ܽ����ˣ���Ծ��¥�������˻����ӣ�����С\n";
    msg +=   "�㴲ǰ���漴�ִ�Ϩ���ۡ�\n";
    msg +=   "���������ߵ���ǰ���ҿ����ӣ����񱻶�ͷ���������ϣ�����§ס��\n";
    msg +=   "���������ſ�һֻ�󲼴���̧���������У��鶯���ӣ��ѰѴ�����\n";
    msg +=   "�����������˸�ִ����һ�ǡ�̧�𲼴���Ծ��¥ȥ��\n"NOR;
    tell_object( ppl,msg );
    ppl->disable_command("verb","����ڴ��в�Ҫ�����������ݾ��ߡ�\n");
    call_out("rascal_leave",5,ppl);
}

void rascal_leave( object ppl )
{
    tell_object(ppl,YEL"��ֻ��������̧����ɿ�����ţ���á�����\n"NOR);
    call_out("arrive",3,ppl);
}

void arrive( object ppl )
{
    tell_object(ppl,YEL"���ǵ�����һ���ط������������˵��ϡ�\n"NOR);
    tell_object(ppl,RED"ֻ����һ�˺Ǻ���Ц���벻�����˶��Ĵ����ô�����뵽��\n"
"ֻ��һ�󾢷�����Ϯ��������֪�����æ�ƴ�������\n"NOR);    
    ppl->enable_path();
    ppl->move(__DIR__"citang");
}
