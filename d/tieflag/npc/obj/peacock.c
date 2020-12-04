#include <ansi.h>
#include <combat.h>
inherit ITEM;
void create()
{
        set_name(GRN"��ȸ��"NOR, ({ "peacock tail","peacock" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ����Ƶ�ԲͲ����������ƽ�������������������صİ�����\n"
);
                set("material", "gold");
                
        } 
         
}
void init()
{
        add_action("do_shoot","shoot");
}
int do_shoot(string arg)
{
        object ob;
        object me;
        int dp;
        int damage;
        if (!arg) return notify_fail("��Ҫ��˭��\n");
    if (query("used")) return notify_fail(this_object()->name()+"ֻ����һ�Ρ�\n");
        me=this_player();
    
            if( !ob
        ||      !ob->is_character()
        ||      !me->is_fighting(ob) )
                return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    
    
    if ( me->query("combat_exp") < 50000 )
                return notify_fail("�㾭��̫���ˣ�û�а취����" + this_object()->name()+"�ķ����ؾ���\n");
    if( environment(me)->query("no_fight") ||
        environment(me)->query("no_magic") ||
        environment(me)->query("no_spells"))
        return notify_fail("���ⲻ��͵Ϯ��\n");
    ob=present(arg,environment(me));
    if (!objectp(ob) || !living(ob)) return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ�á�\n");
    if (!me->is_fighting(ob)) message_vision("$N��Цһ�����ӻ�������һ����������\n",me);
    message_vision("$N����$n���������е�"+this_object()->name()+"...\n",me,ob);
    message_vision(HIC "��ԲͲ�зų�һƬ��â���ԻͲ��ã������������Ŀ�ȸ��ë...\n"NOR,me);
    if (ob->query_skill("perception")/10>random(15)) 
        message_vision("$N������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n",ob);
    else {
    message_vision("��â����$N���ϣ�һ������ʧ�ˡ�\n",ob);
    ob->receive_damage("qi", 0);
        dp = ob->query_skill("dodge",1);
    damage=20000-dp;
    damage/=100;
    if (damage<0) damage=0;
    ob->receive_wound("qi",damage);    
    ob->receive_wound("jing",damage/2);    
    ob->receive_wound("jing",damage/2);    
    }
    COMBAT_D->report_status(ob);                                         
    ob->kill_ob(me); 
    set("used",1);
    me->start_busy(3);
    return 1;
}      
