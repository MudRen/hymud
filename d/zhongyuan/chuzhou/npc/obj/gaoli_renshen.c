// �����˲� /d/city/chuzhou/npc/obj/gaoli_renshen.c
// by lala, 1997-12-13

#include <ansi.h>

inherit ITEM;

int do_eat( string arg );

void create()
{
        set_name( RED"����"YEL"�˲�"NOR, ({"gaoli renshen", "renshen", "corean ginseng", "ginseng" }));
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
����һ֦����ĸ����˲Σ���Լ�������ء������˲���Ϊ�����ҩ�ı���ҽ��Ϊ
����Ч��ҩ���д󲹵Ĺ�Ч���Ҿ�˵���ڴ�Σ�Ĳ��ˣ������𡰵����������á�
LONG
    );
                set("unit", "֦");
                set("value", 160000);
        }
        setup();
}

void init()
{
    add_action("do_eat", "eat");
}    

int do_eat( string arg )
{
    object me = this_player();
    if( !arg ||
       ( arg != "gaoli renshen" 
      && arg != "renshen"
      && arg != "corean ginseng"
      && arg != "ginseng"
      ))
        return 0;
    me->set("sen", me->query("eff_sen") );
    if( me->query("eff_kee") != me->query("max_qi") )
        me->add("eff_kee", ( me->query("max_qi")-me->query("eff_kee") )/2 );
    if( ( me->query("qi") + 100 ) > me->query("eff_kee") )
        me->set("qi", me->query("eff_kee"));
    else
        me->add("qi", 100);
    me->set("gin", me->query("max_gin") );
    me->add("force", 25);
    message_vision(YEL"$N����һ֦�����˲Σ�ֻ����ȫ���ȣ������˻�����\n"NOR, me );
    destruct(this_object());
    return 1;
}
